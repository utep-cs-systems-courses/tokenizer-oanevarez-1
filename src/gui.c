// A fancy interface

#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

void main ()
{
  char userInput[100];

  printf("My fancy interface will repeat your input..\n");
  fgets(userInput, 100, stdin);
  printf("Repeating...\n");
  printf("%s\n", &userInput);

  List *history = init_history();
  char **tokens = tokenize(userInput);

  while(1){
    fputs("History enter h:, Tokenize enter t:, Quit enter q:\n", stdout);
    fflush(stdout);
    int c;
    while((c = getchar()) == '\n');
    if (c == EOF)
      goto done;

    switch(c){
    case 't':
      print_tokens(tokens);
      break;
    case 'h':
      printf("--HISTORY--\n");
      add_history(history, tokens);
      print_history(history);
      free_history(history);
      break;
    case 'q':
      puts("Bye!");
      goto done;
    }
  }

 done:
  return 0;
  
}

