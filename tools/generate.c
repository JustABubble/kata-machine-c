#define NOB_IMPLEMENTATION
#define NOB_STRIP_PREFIX
#include "../nob.h"

#define EXERCISES_DIR "exercises"
#define TEMPLATES_DIR "templates"
#define INCLUDE_DIR "include"

// Find the highest numbered day in the exercises directory
// Returns 0 if no days exist
int find_highest_day(void) {
    File_Paths entries = {0};

    if (!read_entire_dir(EXERCISES_DIR, &entries)) {
        // Directory doesn't exist or is empty
        return 0;
    }

    int highest_day = 0;

    // Parse each directory name to find the highest day number
    for (size_t i = 0; i < entries.count; i++) {
        const char *entry = entries.items[i];

        // Skip hidden files and parent directories
        if (entry[0] == '.') {
            continue;
        }

        // Check if entry starts with "day" followed by digits
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

bool copy_templates_to_day(int day_num) {
    const char *day_dir = temp_sprintf("%s/day%02d", EXERCISES_DIR, day_num);

    // Create the day directory
    if (!mkdir_if_not_exists(day_dir)) {
        nob_log(NOB_ERROR, "Failed to create day directory: %s", day_dir);
        return false;
    }

    File_Paths template_files = {0};

    if (!read_entire_dir(TEMPLATES_DIR, &template_files)) {
        nob_log(NOB_ERROR, "Failed to read templates directory: %s",
                TEMPLATES_DIR);
        nob_log(NOB_ERROR,
                "Make sure the templates directory exists with .c files");
        return false;
    }

    bool success = true;

    // Copy each .c file from templates/ to the day directory
    for (size_t i = 0; i < template_files.count; i++) {
        const char *filename = template_files.items[i];

        // Skip hidden files and non-.c files
        if (filename[0] == '.') {
            continue;
        }

        const char *ext = strrchr(filename, '.');
        if (!ext || strcmp(ext, ".c") != 0) {
            continue;
        }

        const char *src_path = temp_sprintf("%s/%s", TEMPLATES_DIR, filename);
        const char *dst_path = temp_sprintf("%s/%s", day_dir, filename);

        if (!copy_file(src_path, dst_path)) {
            nob_log(NOB_ERROR, "Failed to copy %s to %s", src_path, dst_path);
            success = false;
        }
    }

    da_free(template_files);
    return success;
}

int main(void) {
    // Create exercises directory if it doesn't exist
    if (!mkdir_if_not_exists(EXERCISES_DIR)) {
        nob_log(NOB_ERROR, "Failed to create exercises directory");
        return 1;
    }

    int next_day = find_highest_day() + 1;

    nob_log(NOB_INFO, "Generating day%02d exercises...", next_day);

    if (!copy_templates_to_day(next_day)) {
        nob_log(NOB_ERROR, "Failed to generate exercises for day%02d",
                next_day);
        return 1;
    }

    nob_log(NOB_INFO, "Successfully generated exercises/day%02d", next_day);
    nob_log(NOB_INFO, "Start implementing the exercises in exercises/day%02d/",
            next_day);

    return 0;
}
