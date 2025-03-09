#define NOB_IMPLEMENTATION
#define NOB_STRIP_PREFIX
#include "nob.h"

#include "folders.h"

#define COMMON_CFLAGS "-Wall", "-Wextra", "-pedantic", "-ggdb"

int main(int argc, char **argv) {
    NOB_GO_REBUILD_URSELF(argc, argv);

    const char *program_name = shift(argv, argc);

    Cmd cmd = {0};

    if (!mkdir_if_not_exists(BUILD_DIR))
        return 1;
    if (!mkdir_if_not_exists(TOOLS_BUILD_DIR))
        return 1;

    cmd_append(&cmd, "cc", COMMON_CFLAGS, "-o", TOOLS_BUILD_DIR "generator",
               TOOLS_DIR "generator.c");
    if (!cmd_run_sync_and_reset(&cmd))
        return 1;

    cmd_append(&cmd, "cc", COMMON_CFLAGS, "-o", TOOLS_BUILD_DIR "test",
               TOOLS_DIR "test.c");
    if (!cmd_run_sync_and_reset(&cmd))
        return 1;

    if (argc <= 0)
        return 0;

    const char *subcmd = shift(argv, argc);

    if (strcmp(subcmd, "generate") == 0) {
        cmd_append(&cmd, TOOLS_BUILD_DIR "generator");
        if (!cmd_run_sync_and_reset(&cmd))
            return 1;
    } else if (strcmp(subcmd, "test") == 0) {
        cmd_append(&cmd, TOOLS_BUILD_DIR "test");
        da_append_many(&cmd, argv, argc);
        if (!cmd_run_sync_and_reset(&cmd))
            return 1;
    }

    return 0;
}
