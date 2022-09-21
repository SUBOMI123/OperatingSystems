#include <stdio.h>
#include "list.h"

int main() 
{
  printf("Write your Tests for your linked list implementation\n");
  
  list_t *mylist;
  
  mylist = list_alloc();
  
  list_free(mylist);
  list_add_to_back(mylist, 1);
  list_add_to_back(mylist, 5);
  list_add_to_back(mylist, 9);
  list_add_to_back(mylist, 10);
  list_add_to_back(mylist, 2);
  printf("\n");
  list_print(mylist);
  printf("\n");
  printf("%d\n", list_length(mylist));
  printf("\n");
  list_add_to_front(mylist, 0);
  printf("\n");
  list_print(mylist);
  printf("\n");
  list_add_at_index(mylist, 13, 3);
  printf("\n");
  list_print(mylist);
  printf("\n");
  list_remove_from_back(mylist);
  printf("\n");
  list_print(mylist);
  printf("\n");
  list_remove_from_front(mylist);
  printf("\n");
  list_print(mylist);
  printf("\n");
  list_remove_at_index(mylist, 3);
  printf("\n");
  list_is_in(mylist, 10);
  printf("\n");
  list_print(mylist);
  printf("\n");
  list_get_elem_at(mylist, 3);
  printf("\n");
  list_print(mylist);
  printf("\n");
  list_get_index_of(mylist, 5);
  printf("\n");
  list_print(mylist);
  
  
 
}