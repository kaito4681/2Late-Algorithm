//
//2023.10.24 A main
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

struct element{
  int data;
  struct element *next;
};

struct element *make_list(int);
struct element *delete_last(struct element *list);
void print_list(struct element *list);
struct element *new_element(int);

int main() {
  struct element *list;
  
  srandom(time(NULL));
  list = make_list(random() % N + N);
  print_list(list);
  list = delete_last(list);
  print_list(list);
  return 0;
}

struct element *make_list(int n) {
  int i;
  struct element *list, *current;
  
  current = list = new_element(random() % N);
  for (i = 1; i < n; i++) {
    current->next = new_element(random() % N);
    current = current->next;
  }
  return list;
}

struct element *new_element(int i){
  struct element *new;
  
  if ((new = malloc(sizeof(struct element))) == NULL) {
    fprintf(stderr, "Error: failure in malloc()\n");
    exit(1);
  }
  
  new->data = i;
  new->next = NULL;
  return new;
}

void print_list(struct element *list){
  while(list != NULL){
    printf("%d ",list->data);
    list = list->next;
  }
  printf("\n");
}

struct element *delete_last(struct element *list){
  struct element *current;

  if(list == NULL){
  }else if(list->next == NULL){
    free(list->next);
    list = NULL;
  }else{
    current = list;
    while(current->next->next != NULL){
      current = current->next;
    }
    free(current->next->next);
    current->next = NULL;
  }
  return list;
}
 