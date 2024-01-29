//
// 2024.01.23 C main
//
#include <stdio.h>
#include <stdlib.h>
#define MAX 99
#define N 9

struct cell {
  int end_vertex;
  int value;
  struct cell *next;
};

void initialize_adjacency_matrix(int adjacency_matrix[N][N]);
void from_matrix_to_list(int adjacency_matrix[N][N],
                         struct cell *adjacency_list[N]);
void print_adjacency_matrix(int adjacency_matrix[N][N]);
void print_adjacency_list(struct cell *adjacency_list[N]);
void Dijkstra_list(struct cell *adjacency_list[N], int start);

int main(int argc, char **aegv) {
  int adjacency_matrix[N][N];
  struct cell *adjacency_list[N];
  
  initialize_adjacency_matrix(adjacency_matrix);
  print_adjacency_matrix(adjacency_matrix);
  from_matrix_to_list(adjacency_matrix, adjacency_list);
  print_adjacency_list(adjacency_list);
  Dijkstra_list(adjacency_list, 0);

  return 0;
}

void Dijkstra_list(struct cell *adjacency_list[N], int start) {
  int i, j, v_k, tmp;
  int D[N], S[N], P[N];
  struct cell *current;
    
  for (i = 0; i < N; i++) {
    D[i] = MAX;
    S[i] = 0;
    P[i] = -1;
  }
  D[start] = 0;
  P[start] = start;
  for (j = 0; j < N; j++) printf("D[%d]=%3d\t", j, D[j]);
  printf("\n");
  
  for (i = 0; i < N; i++) {
    tmp = MAX;
    for (j = 0; j < N; j++) {
      if (S[j] == 0 && tmp > D[i] ) {
	tmp  = D[j];
	v_k = j;
      }
    }
    
    S[v_k] = 1;

    current = adjacency_list[v_k];
    while (current != NULL) {
      if (S[current->end_vertex] == 0 &&
	  D[v_k] + current->value < D[current->end_vertex]) {
	D[current->end_vertex] = D[v_k] + current->value;
	P[current->end_vertex] = v_k;
      }
      current = current->next;
    }
    
    for (j = 0; j < N; j++) printf("D[%1d]=%3d\t", j, D[j]);

    printf("\n");
  }
  for (i = 0; i < N; i++) {
    printf("To %d: %d", i, i);
    tmp = P[i];
    while (tmp != start) {
      printf(" <- %d", tmp);
      tmp = P[tmp];
    }
    printf(" <- %d\n", tmp);
  }
  
}

void initialize_adjacency_matrix(int adjacency_matrix[N][N]) {
  int i, j;
  
    for (i = 0; i < N; i++)
      for (j = 0; j < N; j++) adjacency_matrix[i][j] = 0;
    
    adjacency_matrix[0][1] = adjacency_matrix[1][0] = 3;
    adjacency_matrix[0][2] = adjacency_matrix[2][0] = 4;
    adjacency_matrix[0][3] = adjacency_matrix[3][0] = 3;
    adjacency_matrix[0][4] = adjacency_matrix[4][0] = 2;
    adjacency_matrix[0][6] = adjacency_matrix[6][0] = 8;

    adjacency_matrix[1][2] = adjacency_matrix[2][1] = 3;
    adjacency_matrix[1][3] = adjacency_matrix[3][1] = 6;

    adjacency_matrix[2][3] = adjacency_matrix[3][2] = 2;
    adjacency_matrix[2][4] = adjacency_matrix[4][2] = 3;
    adjacency_matrix[2][5] = adjacency_matrix[5][2] = 4;

    adjacency_matrix[3][4] = adjacency_matrix[4][3] = 2;
    adjacency_matrix[3][5] = adjacency_matrix[5][3] = 3;
    adjacency_matrix[3][6] = adjacency_matrix[6][3] = 5;
    adjacency_matrix[3][7] = adjacency_matrix[7][3] = 8;
    adjacency_matrix[3][8] = adjacency_matrix[8][3] = 9;

    adjacency_matrix[4][5] = adjacency_matrix[5][4] = 7;
    adjacency_matrix[4][6] = adjacency_matrix[6][4] = 4;

    
    adjacency_matrix[5][6] = adjacency_matrix[6][5] = 3;
    adjacency_matrix[5][7] = adjacency_matrix[7][5] = 2;
    adjacency_matrix[5][8] = adjacency_matrix[8][5] = 4;

    adjacency_matrix[6][7] = adjacency_matrix[7][6] = 3;
    adjacency_matrix[6][8] = adjacency_matrix[8][6] = 4;
    
    adjacency_matrix[7][8] = adjacency_matrix[8][7] = 2;
}

void print_adjacency_matrix(int adjacency_matrix[N][N]) {
    int i, j;

    printf("adjacency_matrix\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) printf("%1d ", adjacency_matrix[i][j]);
        printf("\n");
    }
    printf("\n");
}

void from_matrix_to_list(int adjacency_matrix[N][N],
                         struct cell *adjacency_list[N]) {
    int i, j;
    struct cell *last, *temp;

    for (i = 0; i < N; i++) {
        adjacency_list[i] = NULL;
        for (j = 0; j < N; j++) {
            if (adjacency_matrix[i][j] != 0) {
                temp = malloc(sizeof(struct cell));
                temp->end_vertex = j;
                temp->value = adjacency_matrix[i][j];

                if (adjacency_list[i] == NULL) {
                    adjacency_list[i] = temp;
                    last = temp;
                } else {
                    last->next = temp;
                    last = last->next;
                }
            }
        }
    }
}

void print_adjacency_list(struct cell *adjacency_list[N]) {
    int i;
    struct cell *current;

    printf("adjacency_list\n");
    for (i = 0; i < N; i++) {
        current = adjacency_list[i];
        while (current != NULL) {
            printf("edge[%d,%d]=%d\t", i, current->end_vertex, current->value);
            current = current->next;
        }
        printf("\n");
    }
    printf("\n");
}
