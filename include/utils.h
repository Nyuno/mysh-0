#ifndef MYSH_UTILS_H_
#define MYSH_UTILS_H_

char** split_string_with_counting(char* str,
                    const char delimiter,
                    int* count);

void mysh_parse_command(const char* command,
                        int *argc, char*** argv);

#endif // MYSH_UTILS_H_
