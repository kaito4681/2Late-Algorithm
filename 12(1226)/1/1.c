//
// 2023.12.26 1 main
//
#include <stdio.h>
#include <stdlib.h>
#define N 7

struct queue {
    int buffer[N];
    int head, tail;
};

void enqueue(struct queue *Q, int data);
int dequeue(struct queue *Q);
void breadth_first_order(int adjacency_matrix[N][N], int start);

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
    breadth_first_order(adjacency_matrix, 0);

    return 0;
}

void breadth_first_order(int adjacency_matrix[N][N], int start) {
    struct queue Q;
    int i, v;
    int C[N] = {0};
    int inQ[N] = {0};

    Q.head = Q.tail = 0;
    printf("breadth_first_order: ");

    enqueue(&Q, start);
    inQ[start] = 1;
    while (Q.head != Q.tail) {
        v = dequeue(&Q);
        C[v] = 1;
        printf("%d ", v);
        for (i = 0; i < N; i++) {
            if (adjacency_matrix[v][i] == 1 && C[i] == 0 && inQ[i] == 0) {
                enqueue(&Q, i);
                inQ[i] = 1;
            }
        }
    }
    printf("\n");
}

void enqueue(struct queue *Q, int datum) {
    Q->buffer[Q->tail] = datum;
    Q->tail++;
}

int dequeue(struct queue *Q) {
    int data = Q->buffer[Q->head];
    Q->head++;
    return data;
}