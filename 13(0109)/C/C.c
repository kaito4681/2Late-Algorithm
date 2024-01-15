//
//2024.01.09 c main
//
#include <stdio.h>
#include <stdlib.h>
#define N 7

void dfs(int adjacency_matrix[N][N], int start);

int main(){
  int i, j;
  int adjacency_matrix[N][N] = {
    {0, 1, 0, 0, 0, 0, 0},
    {1, 0, 1, 1, 0, 0, 0},
    {0, 1, 0, 1, 1, 0, 0},
    {0, 1, 1, 0, 0, 1, 0},
    {0, 0, 1, 0, 0, 1, 1},
    {0, 0, 0, 1, 1, 0, 1},
    {0, 0, 0, 0, 1, 1, 0}};

  printf("adjacency_matrix\n");
  for(i = 0; i < N ; i++){
    for(j = 0; j < N ; j++){
      printf("%d ",adjacency_matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  
  dfs(adjacency_matrix, 0);
  printf("\n");
  
  return 0;
}



void dfs(int adjacency_matrix[N][N], int start) {
  int i;
  static int C[N] = {0, 0, 0, 0, 0, 0, 0};
  
  C[start] = 1;
  printf("%d ", start);

  for(i = 0; i < N; i++){
    if(adjacency_matrix[start][i] != 0 && C[i] == 0) dfs(adjacency_matrix, i);
  }
}

