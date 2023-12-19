//
//
//
#include<stdio.h> 
#include<stdlib.h>

struct element{
  int data;
  struct element *next;
};


struct element *push(struct element *element, int i);
struct element *new_element(int i);
struct element *pop(struct element *element);
void print_data(struct element *list);

int main(void){
  struct element *S = NULL;

  print_data(S);

  S = push(S,1);
  print_data(S);
  
  S = pop(S);
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


struct element *push(struct element *S, int i){
  struct element *new;

  new = new_element(i);
  if(S == NULL){
  }else{
    new->next = S;
  }
  return new;
}


struct element *pop(struct element *S){
  struct element *next;

  if(S == NULL){
    printf("Error: Stack is Enpty\n");
    return NULL;
  }else if(S->next == NULL){
    free(S);
    return NULL;
  }else{
    next = S->next;
    free(S);
    return next;
  }  
}
