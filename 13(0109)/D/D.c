//
//2024.01.09 D main
//
#include <stdio.h>
#include <stdlib.h>
#define N 7

struct cell{
  int end_vertex;
  int value;
  struct cell *next;
};

struct stack {
  int buffer[N];
  int count;
};

void from_matrix_to_list(int adjacency_matrix[N][N],struct cell *adjacency_list[N]);
void print_adjacency_matrix(int adjacency_matrix[N][N]);
void print_adjacency_list(struct cell *adjacency_list[N]);
void push(struct stack *S, int data);
int pop(struct stack *S);
void depth_first_order(struct cell *adjacency_list[N], int start);


int main(){
  int adjacency_matrix[N][N] = {
    {0, 1, 0, 0, 0, 0, 0},
    {1, 0, 1, 1, 0, 0, 0},
    {0, 1, 0, 1, 1, 0, 0},
    {0, 1, 1, 0, 0, 1, 0},
    {0, 0, 1, 0, 0, 1, 1},
    {0, 0, 0, 1, 1, 0, 1},
    {0, 0, 0, 0, 1, 1, 0}};
  struct cell *adjacency_list[N];
  
  print_adjacency_matrix(adjacency_matrix);
  from_matrix_to_list(adjacency_matrix, adjacency_list);
  print_adjacency_list(adjacency_list);
  depth_first_order(adjacency_list,0);
  
  return 0;
}


void print_adjacency_matrix(int adjacency_matrix[N][N]){
  int i,j;

  printf("adjacency_matrix\n");
  for(i = 0; i < N; i++){
    for(j = 0; j < N; j++)
      printf("%1d ", adjacency_matrix[i][j]);
    printf("\n");
  }
  printf("\n");
}

void from_matrix_to_list(int adjacency_matrix[N][N],struct cell *adjacency_list[N]){
  int i,j;
  struct cell *last, *temp;

  for(i = 0; i < N; i++){
    adjacency_list[i] = NULL;
    for(j = 0; j < N; j++){
      if(adjacency_matrix[i][j] != 0){
	temp = malloc(sizeof(struct cell));
	temp->end_vertex = j;
	temp->value = adjacency_matrix[i][j];
	
	if(adjacency_list[i] == NULL){
	  adjacency_list[i] = temp;
	  last = temp;
	}else{
	  last->next = temp;
	  last = last->next;
	}
      }
    }
  }
}


void print_adjacency_list(struct cell *adjacency_list[N]){
  int i;
  struct cell *current;
  
  printf("adjacency_list\n");
  for(i = 0; i < N; i++){
    current = adjacency_list[i];
    while(current != NULL){
      printf("edge[%d,%d]=%d\t",i,current->end_vertex,current->value);
      current = current->next;
    }
    printf("\n");
  }
}



void depth_first_order(struct cell *adjacency_list[N], int start){
    struct stack S;
    int v, i;
    struct cell *current;
    int C[N] = {0, 0, 0, 0, 0, 0, 0};

    S.count = 0;
    printf("depth_first_order: ");
    
    push(&S, start);
    while (S.count > 0) {
      v = pop(&S);
      if (C[v] == 0) {
	C[v] = 1;
	printf("%d ", v);
	for (i = 0; i < N; i++) {
	  if (C[i] == 0) {
	    current = adjacency_list[i];
	    while(current->next != NULL){
	      if(current->end_vertex == v && current->value == 1){
		push(&S, i);
		break;
	      }
	      current = current->next;
	    }
	  }
	}
      }
    }
    printf("\n");
}

      
void push(struct stack *S, int datum) {
    S->buffer[S->count] = datum;
    S->count++;
}

int pop(struct stack *S) {
  if (S->count > 0) {
    S->count--;
        return S->buffer[S->count];
  } else {
    return -1;
  }
}
