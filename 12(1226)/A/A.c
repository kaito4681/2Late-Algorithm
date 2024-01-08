//
//2023.12.26 A main
//
#include <stdio.h>
#include <stdlib.h>
#define N 6

struct cell{
  int end_vertex;
  int value;
  struct cell *next;
};

void initialize_adjacency_matrix(int adjacency_matrix[N][N]);
void print_adjacency_matrix(int adjacency_matrix[N][N]);
void from_matrix_to_list(int adjacency_matrix[N][N],struct cell *adjacency_list[N]);
void print_adjacency_list(struct cell *adjacency_list[N]);

int main(int argc, char **aegv){
  int adjacency_matrix[N][N];
  struct cell *adjacency_list[N];

  initialize_adjacency_matrix(adjacency_matrix);
  print_adjacency_matrix(adjacency_matrix);
  from_matrix_to_list(adjacency_matrix, adjacency_list);
  print_adjacency_list(adjacency_list);

  return 0;
}



void initialize_adjacency_matrix(int adjacency_matrix[N][N]){
  int i,j;
  
  for(i = 0; i < N; i++)
    for(j = 0; j < N; j++)
      adjacency_matrix[i][j] = 0;

  adjacency_matrix[0][1] = adjacency_matrix[1][0] = 2;
  adjacency_matrix[0][2] = adjacency_matrix[2][0] = 4;
  adjacency_matrix[0][3] = adjacency_matrix[3][0] = 4;
  adjacency_matrix[1][2] = adjacency_matrix[2][1] = 3;
  adjacency_matrix[1][3] = adjacency_matrix[3][1] = 1;
  adjacency_matrix[2][3] = adjacency_matrix[3][2] = 2;
  adjacency_matrix[2][4] = adjacency_matrix[4][2] = 3;
  adjacency_matrix[2][5] = adjacency_matrix[5][2] = 3;
  adjacency_matrix[3][4] = adjacency_matrix[4][3] = 2;
  adjacency_matrix[3][5] = adjacency_matrix[5][3] = 5;
  adjacency_matrix[4][5] = adjacency_matrix[5][4] = 1;
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

  
