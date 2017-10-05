#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

/*
 * PARAMETERS
 *  1. char* str : split 할 문자열
 *  2. const char delimiter : 문자열 구분 문자
 *
 * 어떠한 문자열과 구분 문자를 받아서
 * 문자열을 구분 문자 기준으로 자르고
 * 잘라진 문자열의 배열을 반환함.
 *
 * JAVA, JAVASCRIPT, RUBY, PYTHON의 'String.split' 처럼 구현함.
 * 
 */
char** str_split(char* str,
                 const char delimiter)
{
    char** result         = 0;
    size_t count          = 0;
    char* tmp             = str;
    char* last_delimiter  = 0;
    char delim[2];
    delim[0] = delimiter;
    delim[1] = 0;

    /*
     * 구분 문자로 카운팅을 하며
     * 해당 카운트로 문자열 배열의 메모리를 할당함.
     *
     */
    while (*tmp)
    {
        if (delimiter == *tmp)
        {
            ++count;
            last_delimiter = tmp;
        }
        ++tmp;
    }

    printf("count: %zd", count);
    count += last_delimiter < (str + strlen(str) - 1);
    printf("count: %zd", count);

    ++count;

    // 메모리 할당
    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(str, delim);

        while (token)
        {
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        // 문자열 배열의 끝에 0 입력
        *(result + idx) = 0;
    }

    return result;
}

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
  char* tmp = strdup(command);

  *argv = str_split(tmp, ' ');
  *argc = sizeof(*argv) / sizeof(char*);

  free(tmp);
}
