#include <stdio.h>
#include <string.h>

int count_lines_of_code(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return -1;
    }

    int code_lines = 0;
    char line[1024];
    int in_comment = 0; // flag to track if we're inside a multi-line comment

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0; // remove newline character
        char *trimmed_line = strtok(line, " \t"); // trim leading whitespace

        // check for multi-line comments
        if (in_comment) {
            if (strstr(trimmed_line, "*/")) {
                in_comment = 0;
            }
            continue;
        }

        // check for start of multi-line comment
        if (trimmed_line && strstr(trimmed_line, "/*")) {
            in_comment = 1;
            continue;
        }

        // check if line is not empty and does not start with a comment character
        if (trimmed_line && *trimmed_line != '#' && *trimmed_line != '/') {
            code_lines++;
        }
    }

    fclose(file);
    return code_lines;
}

int main() {
    const char *file_path = "textfile.txt"; // replace with your file path
    int lines = count_lines_of_code(file_path);
    printf("Number of lines of code: %d\n", lines);
    return 0;
}