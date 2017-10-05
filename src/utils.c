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
char** split_string_with_counting(char* str,
                 const char delimiter,
                 int* count)
{
    char** result         = 0;
    *count                = 0;
    char* tmp             = str;
    char* last_delimiter  = 0;
    int isBlank           = 0;
    char delim[2];
    delim[0] = delimiter;
    delim[1] = 0;

    /*
     * 구분 문자로 카운팅을 하며
     * 해당 카운트로 문자열 배열의 메모리를 할당함.
     *
     */
    while (*tmp) {
      if (delimiter == *tmp) {
        last_delimiter = tmp;
        isBlank = 1;
      }  else {
        if (isBlank) {
          ++(*count);
        }
        isBlank = 0;
      }
      ++tmp;
    }

    (*count) += 2;

    /* 
     * 메모리 할당
     * 카운팅을 위해 (*count)-- 을 해줌.
    */
    result = malloc(sizeof(char*) * (*count)--);

    if (result) {
      size_t idx  = 0;
      char* token = strtok(str, delim);

      while (token) {
        *(result + idx++) = strdup(token);
        token = strtok(NULL, delim);
      }
      printf("마지막 문자열 %s", *(result + idx - 1));
      // 문자열 배열의 끝에 0 입력
      *(result + idx) = 0;
    }

    return result;
}

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
  char* tmp = strdup(command);
  printf("command: %s", tmp);

  *argv = split_string_with_counting(tmp, ' ', argc);

  free(tmp);
}
