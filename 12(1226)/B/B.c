//
// 2023.12.26 B main
//
#include <stdio.h>
#include <stdlib.h>
#define MAX 99
#define N 6

void initialize_adjacency_matrix(int adjacency_matrix[N][N]);
void print_adjacency_matrix(int adjacency_matrix[N][N]);
void Dijkstra_matrix(int adjacency_matrix[N][N], int start);

int main(int argc, char **argv) {
    int adjacency_matrix[N][N];

    initialize_adjacency_matrix(adjacency_matrix);
    print_adjacency_matrix(adjacency_matrix);
    Dijkstra_matrix(adjacency_matrix, 0);

    return 0;
}

void initialize_adjacency_matrix(int adjacency_matrix[N][N]) {
    int i, j;

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
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

void print_adjacency_matrix(int adjacency_matrix[N][N]) {
    int i, j;

    printf("adjacency_matrix\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            printf("%1d ", adjacency_matrix[i][j]);
        printf("\n");
    }
    printf("\n");
}



void Dijkstra_matrix(int adjacency_matrix[N][N], int start) {
    int i, j, v_k;
    int D[N], S[N];

    for (i = 0; i < N; i++) {
        D[i] = MAX;
        S[i] = 0;
    }
    D[start] = 0;
    for (j = 0; j < N; j++)
        printf("D[%d]=%3d\t", j, D[j]);
    printf("\n");

    for (i = 0; i < N - 1; i++) {
        // 最小距離を見つける
        v_k = -1;
        for (j = 0; j < N; j++) {
            if (!S[j] && (v_k == -1 || D[j] < D[v_k]))
                v_k = j;
        }

        // 選択された頂点を集合に入れる
        S[v_k] = 1;

        // 連接する頂点の距離を更新
        for (j = 0; j < N; j++) {
            if (S[j] != 1 && adjacency_matrix[v_k][j] && D[v_k] + adjacency_matrix[v_k][j] < D[j]) {
                D[j] = D[v_k] + adjacency_matrix[v_k][j];
            }
        }

        // 現在の距離を出力
        printf("v_k = %d\n", i + 1);
        for (j = 0; j < N; j++)
            printf("D[%d]=%3d\t", j, D[j]);
        printf("\n");
    }
}
