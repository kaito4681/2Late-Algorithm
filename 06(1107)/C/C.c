//
//2023,11.07 C main
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
void make_frequency(struct element*,int *);
void print_data(struct element *list);
void print_frequency(int *);
void print_sort(int *);

int main(int argc,char *argv[]){
  int frequency[N];
  struct element *head;
  
  srandom(time(NULL));
  head = make_list(N);
  print_data(head);
  make_frequency(head,frequency);
  print_frequency(frequency);
  print_sort(frequency);
  return 0;
}

void print_sort(int *frequency){
  int i,j;
  printf("print_sort:");
  for(i = 0;i < N;i++){
    for(j = 0;j < frequency[i];j++){
      printf(" %d",i);
    }
  }
  printf("\n");
}

 
void make_frequency(struct element *head, int *frequency){
  int i;

  for(i = 0; i < N; i++){
    frequency[i] = 0;
  }
  for(;head != NULL; head = head->next){
    frequency[head->data]++;
  }
}

void print_frequency(int *frequency){
  int i;
  printf("print_frequency:");
  for(i = 0;i < N;i++){
    printf(" %d",frequency[i]);   
  }
  printf("\n");
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
  current = list = new_element(random() % 10);
  for(i = 1;i < n ; i++){
    current->next = new_element(random() % 10);
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
  return new;
}


    
 
    
      


