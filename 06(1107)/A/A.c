//
//2023,11.07 A main
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

struct element{
  int data;
  struct element *next;
};

int count(struct element*, int);
void print_data(struct element *list);

int main(int argc,char *argv[]){
  int value;
  struct element *head;
  struct element *make_list(int);

  if(argc != 2){
    fprintf(stderr,"\nUsage: %s <value>\nvalue must be integer, 0 <= value <= 9.\n\n",argv[0]);
    exit(1);
  }
  value = atoi(argv[1]);
  srandom(time(NULL));
  head = make_list(N);
  print_data(head);
  printf("count(list, %d) = %d\n",value,count(head,value)); 
  return 0;
}


int count(struct element *head,int value){
  int num = 0;
  struct element *p = head;
  for(;p != NULL;p = p->next){
    if(p->data == value){
      num+=1;
    }
  }
  return num;
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


    
 
    
      


