#include "shell.h"

int is_executable(const char *path) {
    struct stat st;

    if (stat(path, &st) == 0 && S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR)) {
        return (1);
    }
    return (0);
}

char *extract_substring(const char *str, int start, int end) {
    int len = end - start;
    char *buf = (char *)malloc(len + 1);

    if (len >= sizeof(char) && len < sizeof(buf)) {
        strncpy(buf, str + start, len);
        buf[len] = '\0';
        return (buf);
    }
    return (NULL);
}

char *find_command_path(info_t *info, const char *path_str, const char *cmd) {
    if (!path_str || !cmd) {
        return (NULL);
    }

    if (strlen(cmd) > 2 && strncmp(cmd, "./", 2) == 0) {
        if (is_executable(cmd)) {
            return (strdup(cmd));
        }
    }

    int curr_pos = 0;
    int i = 0;

    while (path_str[i]) {
        if (path_str[i] == ':') {
            char *path = extract_substring(path_str, curr_pos, i);

            if (path) {
                char full_path[MAX_PATH_LEN]; // Define MAX_PATH_LEN appropriately
                snprintf(full_path, sizeof(full_path), "%s/%s", path, cmd);

                if (is_executable(full_path)) {
                    return (strdup(full_path));
                }
            }

            curr_pos = i + 1;
        }
        i++;
    }

    return (NULL);
}
