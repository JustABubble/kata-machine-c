#define NOB_IMPLEMENTATION
#define NOB_STRIP_PREFIX
#include "../nob.h"

#define EXERCISES_DIR "exercises"
#define TESTS_DIR "tests"
#define INCLUDE_DIR "include"
#define BUILD_DIR "build"
#define BUILD_TESTS_DIR BUILD_DIR "/tests"

typedef struct {
    const char *name;
    int score;
} TestMatch;

typedef struct {
    TestMatch *items;
    size_t count;
    size_t capacity;
} TestMatches;

static inline int min3(int a, int b, int c) {
    int min = a;
    if (b < min)
        min = b;
    if (c < min)
        min = c;
    return min;
}

int levenshtein_distance(const char *s1, const char *s2) {
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);

    int matrix[len1 + 1][len2 + 1];

    for (size_t i = 0; i <= len1; i++) {
        matrix[i][0] = (int)i;
    }
    for (size_t j = 0; j <= len2; j++) {
        matrix[0][j] = (int)j;
    }

    for (size_t i = 1; i <= len1; i++) {
        for (size_t j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            matrix[i][j] = min3(matrix[i - 1][j] + 1,
                                matrix[i][j - 1] + 1, //
                                matrix[i - 1][j - 1] + cost);
        }
    }

    return matrix[len1][len2];
}

void extract_acronym(const char *name, char *acronym, size_t max_len) {
    size_t idx = 0;

    if (name[0] && idx < max_len - 1) {
        acronym[idx++] = name[0];
    }

    for (size_t i = 0; name[i] && idx < max_len - 1; i++) {
        if (name[i] == '_' && name[i + 1]) {
            acronym[idx++] = name[i + 1];
        }
    }

    acronym[idx] = '\0';
}

int calculate_match_score(const char *test_name, const char *query) {
    size_t query_len = strlen(query);

    if (strcmp(test_name, query) == 0) {
        return 10000;
    }

    if (strncmp(test_name, query, query_len) == 0) {
        return 5000;
    }

    const char *pos = strstr(test_name, query);
    if (pos) {
        int offset = (int)(pos - test_name);
        return 3000 - offset * 10;
    }

    int dist = levenshtein_distance(query, test_name);
    int max_dist = (int)query_len / 2;
    if (dist <= max_dist && dist < 5) {
        return 1000 - dist * 100;
    }

    return -1;
}

File_Paths collect_all_tests(void) {
    File_Paths tests = {0};
    File_Paths entries = {0};

    if (!read_entire_dir(TESTS_DIR, &entries)) {
        nob_log(NOB_ERROR, "Failed to read tests directory");
        return tests;
    }

    for (size_t i = 0; i < entries.count; i++) {
        const char *name = entries.items[i];
        size_t len = strlen(name);

        if (len > 7 && strcmp(name + len - 7, "_test.c") == 0) {
            char *exercise = malloc(len - 6); // len - 7 + 1 for null terminator
            if (!exercise) {
                nob_log(NOB_ERROR,
                        "Failed to allocate memory for exercise name");
                continue;
            }
            strncpy(exercise, name, len - 7);
            exercise[len - 7] = '\0';
            da_append(&tests, exercise);
        }
    }

    da_free(entries);
    return tests;
}

int compare_matches(const void *a, const void *b) {
    const TestMatch *match_a = (const TestMatch *)a;
    const TestMatch *match_b = (const TestMatch *)b;
    return match_b->score - match_a->score;
}

TestMatches find_matching_tests(const char *query) {
    TestMatches matches = {0};
    File_Paths all_tests = collect_all_tests();

    for (size_t i = 0; i < all_tests.count; i++) {
        int score = calculate_match_score(all_tests.items[i], query);
        if (score > 0) {
            TestMatch match = {.name = all_tests.items[i], .score = score};
            da_append(&matches, match);
        }
    }

    if (matches.count > 0) {
        qsort(matches.items, matches.count, sizeof(TestMatch), compare_matches);
    }

    return matches;
}

int find_highest_day(void) {
    File_Paths entries = {0};

    if (!read_entire_dir(EXERCISES_DIR, &entries)) {
        return 0;
    }

    int highest_day = 0;

    for (size_t i = 0; i < entries.count; i++) {
        const char *entry = entries.items[i];

        if (strncmp(entry, "day", 3) == 0 && isdigit(entry[3])) {
            int day_num = atoi(entry + 3);
            if (day_num > highest_day) {
                highest_day = day_num;
            }
        }
    }

    da_free(entries);
    return highest_day;
}

bool compile_and_run_test(const char *exercise_name, int day_num) {
    const char *test_path =
        temp_sprintf("%s/%s_test.c", TESTS_DIR, exercise_name);
    const char *impl_path =
        temp_sprintf("%s/day%02d/%s.c", EXERCISES_DIR, day_num, exercise_name);
    const char *output_path =
        temp_sprintf("%s/%s_test", BUILD_TESTS_DIR, exercise_name);

    if (get_file_type(test_path) != NOB_FILE_REGULAR) {
        nob_log(NOB_ERROR, "Test file not found: %s", test_path);
        return false;
    }

    if (get_file_type(impl_path) != NOB_FILE_REGULAR) {
        nob_log(NOB_ERROR, "Implementation file not found: %s", impl_path);
        nob_log(NOB_ERROR, "Make sure you have generated exercises for day%02d",
                day_num);
        return false;
    }

    if (!mkdir_if_not_exists(BUILD_DIR)) {
        nob_log(NOB_ERROR, "Failed to create build directory");
        return false;
    }
    if (!mkdir_if_not_exists(BUILD_TESTS_DIR)) {
        nob_log(NOB_ERROR, "Failed to create build/tests directory");
        return false;
    }

    nob_log(NOB_INFO, "Compiling test for %s (day%02d)...", exercise_name,
            day_num);

    Cmd cmd = {0};
    cmd_append(&cmd, "cc", "-Wall", "-Wextra");
    cmd_append(&cmd, "-I", INCLUDE_DIR);
    cmd_append(&cmd, "-o", output_path);
    cmd_append(&cmd, test_path, impl_path);

    if (!cmd_run(&cmd)) {
        nob_log(NOB_ERROR, "Failed to compile test for %s", exercise_name);
        return false;
    }

    nob_log(NOB_INFO, "Running test for %s...", exercise_name);

    Cmd run_cmd = {0};
    cmd_append(&run_cmd, output_path);

    if (!cmd_run(&run_cmd)) {
        return false;
    }

    return true;
}

void usage(const char *program_name) {
    nob_log(NOB_INFO, "Usage: %s [exercise_name]", program_name);
    nob_log(NOB_INFO, "");
    nob_log(NOB_INFO, "Run a specific test:");
    nob_log(NOB_INFO, "  %s stack           # Exact match", program_name);
    nob_log(NOB_INFO, "");
    nob_log(NOB_INFO, "Run all tests:");
    nob_log(NOB_INFO, "  %s                 # No argument runs all tests",
            program_name);
}

int main(int argc, char **argv) {
    const char *program_name = shift(argv, argc);

    int latest_day = find_highest_day();

    if (latest_day == 0) {
        nob_log(NOB_ERROR, "No exercises found. Run './nob generate' first");
        return 1;
    }

    if (argc == 0) {
        File_Paths all_tests = collect_all_tests();

        if (all_tests.count == 0) {
            nob_log(NOB_ERROR, "No test files found in %s", TESTS_DIR);
            return 1;
        }

        nob_log(NOB_INFO, "Running all %zu tests from day%02d...",
                all_tests.count, latest_day);
        nob_log(NOB_INFO, "");

        int passed = 0;
        int failed = 0;

        for (size_t i = 0; i < all_tests.count; i++) {
            if (compile_and_run_test(all_tests.items[i], latest_day)) {
                passed++;
            } else {
                failed++;
            }
            nob_log(NOB_INFO, "");
        }

        nob_log(NOB_INFO, "========================================");
        nob_log(NOB_INFO, "Test Summary:");
        nob_log(NOB_INFO, "  Passed: %d", passed);
        nob_log(NOB_INFO, "  Failed: %d", failed);
        nob_log(NOB_INFO, "  Total:  %zu", all_tests.count);
        nob_log(NOB_INFO, "========================================");

        for (size_t i = 0; i < all_tests.count; i++) {
            free((void *)all_tests.items[i]);
        }
        da_free(all_tests);

        return failed > 0 ? 1 : 0;
    }

    const char *query = shift(argv, argc);
    TestMatches matches = find_matching_tests(query);

    if (matches.count == 0) {
        nob_log(NOB_ERROR, "No tests match '%s'", query);
        nob_log(NOB_INFO, "");
        usage(program_name);
        return 1;
    }

    if (matches.count > 1) {
        nob_log(NOB_INFO, "Multiple matches found for '%s':", query);
        size_t show_count = matches.count < 5 ? matches.count : 5;
        for (size_t i = 0; i < show_count; i++) {
            nob_log(NOB_INFO, "  %zu. %s (score: %d)", i + 1,
                    matches.items[i].name, matches.items[i].score);
        }
        if (matches.count > 5) {
            nob_log(NOB_INFO, "  ... and %zu more", matches.count - 5);
        }
        nob_log(NOB_INFO, "Running best match: %s", matches.items[0].name);
        nob_log(NOB_INFO, "");
    }

    const char *best_match = matches.items[0].name;
    bool success = compile_and_run_test(best_match, latest_day);

    da_free(matches);

    return success ? 0 : 1;
}
