//
//2023,10.17 D main
//
#define N 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct record{
  int data;
  struct record *next;
}RECORD;

void swap(RECORD *a);
RECORD *make_list(int n);
void print_data(RECORD *list);

int main(){
  int i;
  RECORD *head;

  srandom(time(NULL));
  head = make_list(N);
  
  print_data(head);
  for(i = 0;i < N;i++){
      swap(head);
      print_data(head);
  }
  
  return 0;
}


void print_data(RECORD *list){
  if(list == NULL){
    printf("\n");
    return;
  }

  printf("%d ", list->data );
  print_data(list->next);
}



RECORD *make_list(int n){
  int i;
  RECORD *list,*current;
  RECORD *new_record(int);
  current = list = new_record(random() % 10 + 1 );
  for(i = 1;i < n ; i++){
    current->next = new_record(random() % 10 + 1);
    current = current->next;
  }
  return list;
}

RECORD *new_record(int i){
  RECORD *new;
  if((new = (RECORD *)malloc(sizeof(RECORD) )) == NULL){
    fprintf(stderr, "Error: failure in malloc()\n");
    exit(1);
  }
  new->data = i;
  new->next = NULL;
  return (new);
}



void swap(RECORD *head){
  void swap_data(RECORD *a);
  if(head->next == NULL){
  }else{
    swap_data(head);
    swap(head->next);
  }

  return;
}

void swap_data(RECORD *a){
  int b;
  if(a->data > a->next->data){
    b = a->next->data;
    a->next->data = a->data;
    a->data = b;
  }
  return;
}


    
 
    
      

