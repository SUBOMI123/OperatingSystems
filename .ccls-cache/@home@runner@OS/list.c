// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

#include "list.h"
node_t* node_alloc(){
  node_t* node = (node_t*)malloc(sizeof(node_t));
  node->next = NULL;
  return node;
}

void node_free(node_t* n){
  free(n);
}

list_t *list_alloc() { 
  list_t* list = (list_t*)malloc(sizeof(list_t));
  list->head = NULL;
  return list;
  }

void list_free(list_t *l) {
  node_t *current = l->head;
  while (current){
    node_t *temp = current;
    current = current->next;
    free(temp);
    }
    free(l->head);
    l->head = NULL;
}

void list_print(list_t *l) {
  node_t *current = l->head;
  while (current){
    printf("%d ",current->value);
    current = current->next;
  } 
}
int list_length(list_t *l) {
  int counter = 0;
  node_t *current = l->head;
  while(current){
  counter++;
  current = current->next;
  } 
  return counter;
   }

void list_add_to_back(list_t *l, elem value) {
  node_t *back = node_alloc();
  back->value = value;
  node_t *current = l->head;
  if(l->head){
    while(current->next){
      current = current->next;
    }
    current->next = back;
  }
  else{
    l->head = back;
  }
}
void list_add_to_front(list_t *l, elem value) {
  node_t *front = node_alloc();
  front->value = value;
  if(l->head){
    front->next =l->head;
    l->head = front;
  }
  else{
    l->head = front;
  }
}
void list_add_at_index(list_t *l, elem value, int index) {
  int count = 0;
  node_t *new_node = node_alloc();
  new_node->value = value;
  node_t* current =l->head;
  
  if(index == 0){
    list_add_to_front(l, value);
  }
  else if (l->head){
    while(count != index-1){
      current = current->next;
      count++;
    }
    new_node->next = current->next;
    current->next = new_node;
    }
  else{
    l->head = new_node;
  }
}

elem list_remove_from_back(list_t *l){
  if (list_length(l) == 1){
    node_t* temp = l -> head;
    elem val = temp->value;
    free(temp);
    l->head = NULL;
    return val;
  }
  node_t* current = l -> head;
  while(current->next->next != NULL){
    current = current -> next;
  }
  node_t* temp = current -> next;
  elem val = temp->value;
  free(temp);
  current -> next = NULL;
  return val;
}

elem list_remove_from_front(list_t *l) {
  node_t *temp = l -> head;
  if (temp != NULL){
  l -> head = temp -> next;
  elem val = temp->value;
  free(temp);
  return temp -> value;
  }
  return -1;
}

elem list_remove_at_index(list_t *l, int index){
  node_t *temp = l -> head;
  int i;
  if (index == 0){
    temp = temp->next;
    temp->next = NULL;
    elem res = temp->value;
    free(temp);
    return res;
  }
  else{
    for(i=0; i < index - 1; i++){
      temp = temp->next;
    }
    node_t* del = temp->next;
    temp->next = temp->next->next;
    printf("\nElement removed: %d\n", del->value);
    elem res = del->value;
    del->next = NULL;
    free(del);
    return res;
  }
}

bool list_is_in(list_t *l, elem value) { 
  if (l->head == NULL){
    return false;
  }
  else{
    node_t *current = l->head;
    while(current){
      if (current->value == value){
        return true;
      }
      current = current->next;
    }
  }
  return false; 
  }

elem list_get_elem_at(list_t *l, int index) { 
  int count = 0;
  node_t *current = l->head;
  if (l->head){
    while(count != index){
      current = current->next;
      count++;
    }
    return current->value;
  }
  else{
    return -1;
  }
} 

int list_get_index_of(list_t *l, elem value) { 
  if (l->head == NULL){
    return -1;
  }
  else{
    int count = 0;
    node_t *current = l->head;
    while(current){
      if (current->value == value){
        return count;
      }
      current = current->next;
      count++;
    }
  }
  return -1;
  }

