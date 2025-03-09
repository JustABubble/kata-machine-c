#include <dirent.h>
#include <stdlib.h>
#include <stdbool.h>

#define NOB_IMPLEMENTATION
#define NOB_STRIP_PREFIX
#include "../nob.h"

#include "../folders.h"

char *get_exercise_dir(void) {
    File_Paths children = {0};
    if (!read_entire_dir(EXERCISE_DIR, &children)) return NULL;

    return temp_sprintf(EXERCISE_DIR"day%d/", children.count - 1);
}

bool copy_all(const char* exercise_dir) {
    File_Paths children = {0};
    if (!read_entire_dir(TEMPLATE_DIR, &children)) return false;

    for (size_t i = 0; i < children.count; ++i) {
        if (children.items[i][0] == '.') {
            continue;
        }

        const char *src_path = temp_sprintf(TEMPLATE_DIR"%s", children.items[i]);
        const char *dst_path = temp_sprintf("%s%s", exercise_dir, children.items[i]);
        if (!copy_file(src_path, dst_path)) return false;
    }

    return true;
}

int main(void) {
    if (!mkdir_if_not_exists(EXERCISE_DIR)) return 1;

    const char *output_path = get_exercise_dir();

    if (!mkdir_if_not_exists(output_path)) return 1;

    if (!copy_all(output_path)) return 1;

    return 0;
}
