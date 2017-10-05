#ifndef MYSH_UTILS_H_
#define MYSH_UTILS_H_

char** stirng_split(char* str,
                    const char delimiter);

void mysh_parse_command(const char* command,
                        int *argc, char*** argv);

#endif // MYSH_UTILS_H_
