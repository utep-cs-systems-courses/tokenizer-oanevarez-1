/*
History
 */

#include <stdlib.h>
#include <stdio.h>
#include "history.h"

/*Initialize the linked list to keep the history. */
List* init_history()
{
  List *user_hist = (List*)malloc(sizeof(Item)*300);
  return user_hist;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str)
{
  Item *node = list->root;

  //begin history log
  if (node == NULL){
    node = (Item*)malloc(sizeof(Item));
    node->id =1;
    node->str = str;
    node->next = NULL;
    list->root = node;
    printf("%s\n", node->str);
    printf("%d\n", node->id);
  }else{

    int id=2;
    while(node->next){
      node = node->next;
      id++;
    }
    node->next = (Item*)malloc(sizeof(Item));
    node->next->id = id;
    node->next->str = str;
    node->next->next = NULL;
    printf("%s\n", node->next->str);
    printf("%d\n", node->next->id);
  } 
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id)
{
  Item *node = list->root;

  while(node){
    if(node->id == id) return node->str;
    node = node->next;
  }
  return "No history...";
}

/*Print the entire contents of the list. */
void print_history(List *list)
{
  Item *node = list->root;
  while(node){
    printf("%s\n", node->str);
    node =node->next;
  }
}

/*Free the history list and the strings it references. */
void free_history(List *list)
{
  Item *node = list->root;
  while(node){
    free(node);
    node = node->next;
  }
  free(list);
}
