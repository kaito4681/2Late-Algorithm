//
//2023,10.17 A main
//
#include <stdio.h>

typedef struct record{
  int data;
  struct record *next;
}RECORD;

void concatenate(RECORD *a,RECORD *b);
void print_data(RECORD *list);

int main(){
  RECORD a,b;

  a.data = 1;
  b.data = 2;
  a.next = b.next = NULL;

  print_data(&a);
  print_data(&b);
  concatenate(&a,&b);
  print_data(&a);
    
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

