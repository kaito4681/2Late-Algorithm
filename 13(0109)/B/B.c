//
//2024.01.09 B main
//
#include <stdio.h>
#include <stdlib.h>
#define MAX 99
#define N 6

struct list{
  int x;
  struct list *next;
};

void initialize_adjacency_matrix(int adjacency_matrix[N][N]);
void print_adjacency_matrix(int adjacency_matrix[N][N]);
void Dijkstra_matrix(int adjacency_matrix[N][N], int start);


int main(int argc, char **aegv){
  int adjacency_matrix[N][N];

  initialize_adjacency_matrix(adjacency_matrix);
  print_adjacency_matrix(adjacency_matrix);
  Dijkstra_matrix(adjacency_matrix, 0);
  
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

void Dijkstra_matrix(int adjacency_matrix[N][N], int start) {
    int i, j, v_k, tmp;
    int D[N], S[N], path[N];

    for (i = 0; i < N; i++) {
        D[i] = MAX;
        S[i] = 0;
        path[i] = -1;
    }

    D[start] = 0;

    for (i = 0; i < N - 1; i++) {
        tmp = MAX;
        for (j = 0; j < N; j++) {
            if (S[j] == 0 && tmp > D[j]) {
                tmp = D[j];
                v_k = j;
            }
        }

        S[v_k] = 1;

        for (j = 0; j < N; j++) {
            if (adjacency_matrix[v_k][j] > 0 && S[j] == 0 &&
                D[j] > D[v_k] + adjacency_matrix[v_k][j]) {
                D[j] = D[v_k] + adjacency_matrix[v_k][j];
                path[j] = v_k; 
            }
        }
    }

    for (i = 0; i < N; i++) {
        int current = path[i];

        printf("To %d: %d ", i, i);
        while (current != -1) {
            printf("<- %d ", current);
            current = path[current];
        }
        printf("\n");
    }
}