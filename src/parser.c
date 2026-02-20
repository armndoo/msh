#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char** parse_input(char* str) {
  
  char* str_tokenized;
  char* delim=" \t\n\r";
  char* w_ptr=str;
  char** argv;

  int num_words = 0;
  int in_word = 0;
  int i = 0;

  if(!w_ptr) return NULL;

  for(i = 0; str[i] != '\0'; i++) {
    if(!isspace(str[i])) {
      if(!in_word) {
        num_words++;
        in_word = 1;
      }
    } else if(isspace(str[i])) {
      in_word = 0;
    }
  }
  i = 0;
  if(num_words == 0) {
     argv = malloc(sizeof(char*));
  } else {
      argv = malloc((num_words +2) * sizeof(char*));
  }
  str_tokenized = strsep(&w_ptr,delim);

  while(str_tokenized != NULL) {
    if(str_tokenized[0] != '\0') {
      argv[i] = str_tokenized;
      i++;
    }
      str_tokenized = strsep(&w_ptr, delim);
  }
  argv[i] = NULL;
  return argv;
}

