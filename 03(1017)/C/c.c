//
//2023,10.17 c main
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct record{
  int data;
  struct record *next;
}RECORD;

void swap_data(RECORD *a);
void concatenate(RECORD *a,RECORD *b);
void print_data(RECORD *list);

int main(){
  RECORD a,b;
  RECORD *list;

  srandom(time(NULL));
  list = &a;
  a.data = random() % 10 + 1;
  b.data = random() % 10 + 1;
  a.next = b.next = NULL;
  
  concatenate(&a,&b);
  print_data(list);
  swap_data(&a);
  print_data(list);
  
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

void concatenate(RECORD *a,RECORD *b){
  a->next = b;
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

    
  


  
    
    
      

