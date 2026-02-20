#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <strings.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h> 
#include "path_utils.h"
#include "parser.h"
#include "builtins.h"

int main(void) {
  setbuf(stdout, NULL);
  char user_input[1024];
  char** args;
  char* which_res;
  int dispatch;
  
  while(1){
    printf("> ");
    if(fgets(user_input, sizeof(user_input), stdin)) {
      user_input[strcspn(user_input, "\n")] = '\0';
      args = parse_input(user_input);
      if(!args || !args[0]) continue;
      which_res = which(args[0]);
      if(!which_res) {
        fprintf(stderr,"%s: command not found \n", user_input);
      }
      dispatch = dispatcher(args);
    }
  }   
  return 0;    
}


