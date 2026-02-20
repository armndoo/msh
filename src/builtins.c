#include <complex.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "path_utils.h"
#include "parser.h"


int exec_echo(char* str) {
  if(!strcmp(str, "\n")) {
    printf("%s \n", str);
    return 1;
  } else if(!strcmp(str,"/n")) {
    printf("/n");
    return 1;
  } else {
    printf("%s \n",str);
    return 1;
  }
  return 0;
}

int exec_type(char** argv) {
  int found = 0;
  char* builtins[] = {"cd","type","echo","exit","pwd",NULL};
  char* after_command = argv[1];
  char* path_command = which(after_command);
  if (argv[1] == NULL) {
     printf("type: missing operand\n"); return 1;
  }
  if(strcmp(argv[0], "type")) {
    return 1;
  }
  else {
    for(int i = 0; builtins[i] != NULL; i++){
      if(!strcmp(argv[1], builtins[i])) {
        found = 1;
        printf("%s is a builtin command", argv[1]); 
        return 1;
      } 
      if(path_command) {
        printf("%s is %s \n", after_command, path_command);
        free(path_command);
        return 1;
      }
    }
    if(!found) {
      printf("%s: command not found",argv[1]);      
      return 1;
    }
  }
  return 0;
}

int exec_exit() {
  exit(1);
}

int dispatcher(char** argv) {
   if(!strcmp(argv[0],"echo")){
     exec_echo(argv[1]);
     return 1;
  }
  if(!strcmp(argv[0],"type")){
       exec_type(argv);
       return 1;
  }
  if(!strcmp(argv[0],"exit")) {
    exec_exit();
    return 1;
  }
  return 0;
}
