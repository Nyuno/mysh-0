#include <stdio.h>
#include <string.h>

#include "commands.h"

int do_cd(int argc, char** argv) {
  if (!validate_cd_argv(argc, argv))
    return -1;

  // TODO: Fill it!
  return 0;
}

int do_pwd(int argc, char** argv) {
  printf("begin do_pwd\n");
  if (!validate_pwd_argv(argc, argv))
    return -1;

  printf("Yeah PWD\n");

  return 0;
}

int validate_cd_argv(int argc, char** argv) {
  // TODO: Fill it!
  return 1;
}

int validate_pwd_argv(int argc, char** argv) {
  if (argc < 2) {
    return 1;
  }

  return 0;
}
