//
//2023.10.24 B  main
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

struct element{
  int data;
  struct element *next;
};

struct element *make_list(int n);
double average(struct element *list);
void print_list(struct element *list);
struct element *new_element(int);

int main() {
  struct element *list;
  
  srandom(time(NULL));
  list = make_list(random() % N + N);
  print_list(list);
  printf("average = %f\n",average(list));
  return 0;
}

double average(struct element *list){
  struct element *current;
  int sum = 0,n = 0;
  
  current = list;
  while(current->next != NULL){
    sum += current->data;
    n++;
    current = current->next;
  }
  return (double)sum / (double)n;
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