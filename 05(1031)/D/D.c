//
// 2023.10.31 D main 
//
#include<stdio.h> 
#include<stdlib.h>

struct element{
  int data;
  struct element *next;
};


void push(struct element **element, int i);
struct element *new_element(int i);
void pop(struct element **element);
void print_data(struct element *list);

int main(void){
  struct element *S = NULL;

  print_data(S);

   push(&S,1);
  print_data(S);
  
  pop(&S);
  print_data(S);
  
  push(&S,2);
  print_data(S);

  push(&S,3);
  print_data(S);
  
  push(&S,5);
  print_data(S);
  
  push(&S,8);
  print_data(S);
  
  push(&S,13);
  print_data(S);

  push(&S,21);
  print_data(S);

  while(S != NULL){
    pop(&S);
    print_data(S);
  }

  pop(&S);
  print_data(S);

  
  push(&S,34);
  print_data(S);

  return 0;
}

struct element *new_element(int i){
  struct element *new;
  
  if((new = malloc(sizeof(struct element))) == NULL){
      fprintf(stderr,"Error:failure in malloc()\n");
      exit(1);
  }
  new->data = i;
  new->next = NULL;
  return new;
}



void print_data(struct element *list){
  while(list != NULL){
    printf("%d ",list->data);
    list = list->next;
  }
  printf("\n");
}


void push(struct element **S, int i){
  struct element *new;

  new = new_element(i);
  if(*S == NULL){
  }else{
    new->next = *S;
  }
  *S = new;
}


void pop(struct element **S){
  struct element *next;

  if(*S == NULL){
    printf("Error: Stack is Empty\n");
  }else if((*S)->next == NULL){
    free(*S);
    *S = NULL;
  }else{
    next = (*S)->next;
    free(*S);
    *S = next;
  }  
}
