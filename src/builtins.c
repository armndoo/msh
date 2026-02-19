#include <complex.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "path_utils.h"

int exec_echo(char* str) {
  if(!strcmp(str, "echo")) {
    printf("\n");
    return 1;
  }
  if(!strncmp(str, "echo ", sizeof("echo ")-1)) {
    printf("%s \n", str+5);
    return 1;

  }
  return 0;
}

int exec_type(char* command) {
  int found = 0;
  char* builtins[] = {"cd","type","echo","exit","pwd",NULL};
  char* after_command = command+5;
  char* path_command = which(after_command);
  if(!strcmp(command, "type")) return 1;
  if(!strncmp(command,"type ", sizeof("type ") -1 )) {
    for(int i = 0; builtins[i] != NULL; i++){
      if(!strcmp(command+5, builtins[i])) {
        found = 1;
        printf("%s is a builtin command", command+5);
        return 1;
      } 
      if(path_command) {
        printf("%s is %s \n", after_command, path_command);
        free(path_command);
        return 1;
      }
    }
    if(!found) {
      printf("%s: command not found",command+5);      
      return 1;
    }
  }
  return 0;
}
