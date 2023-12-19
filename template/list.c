//
//2023,10.17 D main
//
#define N 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct element{
  int data;
  struct element *next;
};

void swap(struct element *a);
struct element *make_list(int n);
void print_data(struct element *list);

int main(){
  int i;
  struct element *head;

  srandom(time(NULL));
  head = make_list(N);
  
  print_data(head);
  for(i = 0;i < N;i++){
      swap(head);
      print_data(head);
  }
  
  return 0;
}


void print_data(struct element *list){
  if(list == NULL){
    printf("\n");
    return;
  }

  printf("%d ", list->data );
  print_data(list->next);
}



struct element *make_list(int n){
  int i;
  struct element *list,*current;
  struct element *new_element(int);
  current = list = new_element(random() % 10 + 1 );
  for(i = 1;i < n ; i++){
    current->next = new_element(random() % 10 + 1);
    current = current->next;
  }
  return list;
}

struct element *new_element(int i){
  struct element *new;
  if((new = (struct element *)malloc(sizeof(struct element) )) == NULL){
    fprintf(stderr, "Error: failure in malloc()\n");
    exit(1);
  }
  new->data = i;
  new->next = NULL;
  return (new);
}



void swap(struct element *head){
  void swap_data(struct element *a);
  if(head->next == NULL){
  }else{
    swap_data(head);
    swap(head->next);
  }

  return;
}

void swap_data(struct element *a){
  int b;
  if(a->data > a->next->data){
    b = a->next->data;
    a->next->data = a->data;
    a->data = b;
  }
  return;
}


    
 
    
      

