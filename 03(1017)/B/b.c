//
//2023,10.17 B main
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct record{
  int data;
  struct record *next;
}RECORD;

RECORD *make_list(int);
RECORD *end(RECORD *);
void concatenate(RECORD *a,RECORD *b);
void print_data(RECORD *list);

int main(){
  int value;
  RECORD *listA,*listB;

  srandom(time(NULL));

  value = random() % 10 + 1;
  printf("Size of listA = %d\n",value);
  listA = make_list(value);
  print_data(listA);
  value = random() % 10 + 1;
  printf("Size of listB = %d\n",value);
  listB = make_list(value);
  print_data(listB);
  concatenate(end(listA),listB);
  print_data(listA);
 	
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



RECORD *make_list(int n){
  int i;
  RECORD *list,*current;
  RECORD *new_record(int);
  current = list = new_record(0);
  for(i = 1;i < n ; i++){
    current->next = new_record(i);
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


RECORD *end(RECORD *current){
  static RECORD *result;
  if(current->next == NULL){
    result = current;
  }else{
    result = end(current->next);
  }
  return result;
}

    
    
    
