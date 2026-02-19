#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <strings.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h> 
#include "path_utils.h"

// Function that clears the terminal screen via an Escape Sequence.
void cls() {
  printf("\e[1;1H\e[2J");
}

int main(int argc, char *argv[]) {

  setbuf(stdout, NULL);
  char user_input[1024];
  char** dirs = tokenize_PATH();

  cls();

   do{
      printf("$ > ");
      fgets(user_input, sizeof(user_input), stdin);
      user_input[strcspn(user_input, "\n")] = '\0';

      if(which(user_input) == NULL) {
        if(strcmp(user_input, "exit")) break;
        printf("%s: command not found \n", user_input);
      } else if(strcmp(user_input, "exit")) {
        
      }      
      

    }while(strcmp(user_input, "exit")); 
   
  return 0;    
}


