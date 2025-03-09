#define NOB_IMPLEMENTATION
#define NOB_STRIP_PREFIX
#include "../nob.h"

#include "../folders.h"

#define COMMON_CFLAGS "-Wall", "-Wextra", "-pedantic", "-ggdb"

char *get_exercise_dir(void) {
    File_Paths children = {0};
    if (!read_entire_dir(EXERCISE_DIR, &children)) return NULL;

    return temp_sprintf(EXERCISE_DIR"day%d/", children.count - 2);
}

int main(int argc, char **argv) {
    const char *program_name = shift(argv, argc);

    if (!mkdir_if_not_exists(TEST_BUILD_DIR)) return 1;

    if (argc <= 0) {
        nob_log(ERROR, "No exercise provided");
        fprintf(stderr, "Usage: %s <exercise>\n", program_name);
        return 1;
    }

    const char *exercise_name = shift(argv, argc);
    const char *exercise_path =
        temp_sprintf("%s%s.c", get_exercise_dir(), exercise_name);

    int result = file_exists(exercise_path);
    if (result < 0) {
        nob_log(ERROR, "Could not access %s", exercise_path);
        return 1;
    }

    if (result == 0) {
        nob_log(ERROR, "%s does not exist", exercise_path);
        return 1;
    }

    const char *test_path = temp_sprintf(TEST_DIR"%s_tests.c", exercise_name);
    const char *output_path = temp_sprintf(TEST_BUILD_DIR"%s", exercise_name);

    Cmd cmd = {0};
    cmd_append(&cmd,
               "cc", COMMON_CFLAGS,
               "-I"TEST_DIR"include",
               "-lm",
               "-o", output_path,
               test_path, exercise_path);
    if (!cmd_run_sync_and_reset(&cmd)) return 1;

    cmd_append(&cmd, output_path);
    if (!cmd_run_sync_and_reset(&cmd)) return 1;

    return 0;
}
