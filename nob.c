#define NOB_IMPLEMENTATION
#define NOB_STRIP_PREFIX
#include "nob.h"

#define BUILD_DIR "build"
#define TOOLS_DIR "tools"
#define BUILD_TOOLS_DIR BUILD_DIR "/tools"

bool build_tool(const char *tool_name) {
    const char *source_path = temp_sprintf("%s/%s.c", TOOLS_DIR, tool_name);
    const char *output_path = temp_sprintf("%s/%s", BUILD_TOOLS_DIR, tool_name);

    if (!mkdir_if_not_exists(BUILD_DIR))
        return false;
    if (!mkdir_if_not_exists(BUILD_TOOLS_DIR))
        return false;

    Cmd cmd = {0};
    cmd_append(&cmd, "cc", "-Wall", "-Wextra", "-o", output_path, source_path);

    if (!cmd_run(&cmd)) {
        nob_log(NOB_ERROR, "Failed to build %s", tool_name);
        return false;
    }

    return true;
}

bool run_tool(const char *tool_name, int argc, char **argv) {
    const char *tool_path = temp_sprintf("%s/%s", BUILD_TOOLS_DIR, tool_name);

    Cmd cmd = {0};
    cmd_append(&cmd, tool_path);

    // Pass remaining arguments to the tool
    for (int i = 0; i < argc; i++) {
        cmd_append(&cmd, argv[i]);
    }

    if (!cmd_run(&cmd)) {
        nob_log(NOB_ERROR, "Failed to run %s", tool_name);
        return false;
    }

    return true;
}

void usage(const char *program_name) {
    nob_log(NOB_INFO, "Usage: %s <command> [args]", program_name);
    nob_log(NOB_INFO, "Commands:");
    nob_log(NOB_INFO,
            "  generate           Generate a new day's worth of exercises");
    nob_log(NOB_INFO, "  test <exercise>    Run tests for a specific exercise");
    nob_log(NOB_INFO, "  help               Show this message");
}

int main(int argc, char **argv) {
    NOB_GO_REBUILD_URSELF(argc, argv);

    const char *program_name = shift(argv, argc);

    if (argc == 0) {
        usage(program_name);
        nob_log(NOB_ERROR, "No command provided");
        return 1;
    }

    const char *command = shift(argv, argc);

    if (strcmp(command, "generate") == 0) {
        if (!build_tool("generate"))
            return 1;
        if (!run_tool("generate", argc, argv))
            return 1;
    } else if (strcmp(command, "test") == 0) {
        if (!build_tool("test"))
            return 1;
        if (!run_tool("test", argc, argv))
            return 1;
    } else if (strcmp(command, "help") == 0) {
        usage(program_name);
        return 0;
    } else {
        usage(program_name);
        nob_log(NOB_ERROR, "Unknown command: %s", command);
        return 1;
    }

    return 0;
}
