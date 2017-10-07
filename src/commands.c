#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "commands.h"

// 전역 변수 참조
static char g_current_directory[1024] = "";

int do_cd(int argc, char** argv) {
  if (!validate_cd_argv(argc, argv)) {
    printf("cd: command error\n");
    return -1;
  }

  char directory[1024] = "/";

  if (argc > 1) {
    strcpy(directory, argv[1]);
  }

  if (chdir(directory) == -1) {
    printf("cd: no such file or directory: %s\n", directory);
  }
  return 0;
}

int do_pwd(int argc, char** argv) {
  if (!validate_pwd_argv(argc, argv)) {
    printf("pwd: too many arguments\n");
    return -1;
  }

  getcwd(g_current_directory, sizeof(g_current_directory));
  printf("%s\n", g_current_directory);

  return 0;
}

int validate_cd_argv(int argc, char** argv) {
  if (strcmp(argv[0], "cd") != 0 || argc == 1) {
    return 0;
  } else if (argc > 2 &&
      strcmp(argv[2], "|") != 0 &&
      strcmp(argv[2], ">") != 0) {
    return 0;
  } else {
    return 1;
  }
}

int validate_pwd_argv(int argc, char** argv) {
  if (strcmp(argv[0], "pwd") != 0) {
    return 0;
  } else if (argc < 2) {
    return 1;
  } else {
    return 0;
  }
}
