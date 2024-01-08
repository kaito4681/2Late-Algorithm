//
// 2023.12.26 C main
//
#include <stdio.h>
#include <stdlib.h>
#define N 7

struct stack {
    int buffer[N];
    int count;
};

void push(struct stack *S, int data);
int pop(struct stack *S);
void depth_first_order(int adjacency_matrix[N][N], int start);

int main(int argc, char **argv) {
    int i, j;
    int adjacency_matrix[N][N] = {{0, 1, 0, 0, 0, 0, 0}, {1, 0, 1, 1, 0, 0, 0},
                                  {0, 1, 0, 1, 1, 0, 0}, {0, 1, 1, 0, 0, 1, 0},
                                  {0, 0, 1, 0, 0, 1, 1}, {0, 0, 0, 1, 1, 0, 1},
                                  {0, 0, 0, 0, 1, 1, 0}};

    printf("adjacency_matrix\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", adjacency_matrix[i][j]);
        }
        printf("\n");
    }
    depth_first_order(adjacency_matrix, 0);

    return 0;
}

void depth_first_order(int adjacency_matrix[N][N], int start) {
    struct stack S;
    int i, v;
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
                if (adjacency_matrix[v][i] == 1 && C[i] == 0) {
                    push(&S, i);
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
