// A fancy interface

#include <stdio.h>
#include <stdlib.h>

void main ()
{
  char userInput[100];

  printf("My fancy interface will repeat your input..\n");
  fgets(userInput, 100, stdin);
  printf("Repeating...\n");
  printf("%s\n", &userInput);
  
}

