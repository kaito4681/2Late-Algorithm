//
// 2023.12.26 D main
//
#include <stdio.h>
#include <stdlib.h>
#define N 6

struct cell {
    int end_vertex;
    int value;
    struct cell *next;
};

void initialize_adjacency_list(struct cell *adjacency_list[N]);
void print_adjacency_matrix(int adjacency_matrix[N][N]);
void from_list_to_matrix(struct cell *adjacency_list[N],
                         int adjacency_matrix[N][N]);
void print_adjacency_list(struct cell *adjacency_1ist[N]);

int main(int argc, char **aegv) {
    struct cell *adjacency_list[N];
    int adjacency_matrix[N][N];

    initialize_adjacency_list(adjacency_list);
    print_adjacency_list(adjacency_list);
    printf("\n");
    from_list_to_matrix(adjacency_list, adjacency_matrix);
    print_adjacency_matrix(adjacency_matrix);

    return 0;
}

void initialize_adjacency_list(struct cell *adjacency_list[N]) {
    adjacency_list[0] = (struct cell *)malloc(sizeof(struct cell));
    adjacency_list[0]->end_vertex = 1;
    adjacency_list[0]->value = 2;
    adjacency_list[0]->next = (struct cell *)malloc(sizeof(struct cell));
    adjacency_list[0]->next->end_vertex = 2;
    adjacency_list[0]->next->value = 4;
    adjacency_list[0]->next->next = (struct cell *)malloc(sizeof(struct cell));
    adjacency_list[0]->next->next->end_vertex = 3;
    adjacency_list[0]->next->next->value = 4;
    adjacency_list[0]->next->next->next = NULL;

    adjacency_list[1] = (struct cell *)malloc(sizeof(struct cell));
    adjacency_list[1]->end_vertex = 0;
    adjacency_list[1]->value = 2;
    adjacency_list[1]->next = (struct cell *)malloc(sizeof(struct cell));
    adjacency_list[1]->next->end_vertex = 2;
    adjacency_list[1]->next->value = 3;
    adjacency_list[1]->next->next = (struct cell *)malloc(sizeof(struct cell));
    adjacency_list[1]->next->next->end_vertex = 3;
    adjacency_list[1]->next->next->value = 1;
    adjacency_list[1]->next->next->next = NULL;

    adjacency_list[2] = (struct cell *)malloc(sizeof(struct cell));
    adjacency_list[2]->end_vertex = 0;
    adjacency_list[2]->value = 4;
    adjacency_list[2]->next = (struct cell *)malloc(sizeof(struct cell));
    adjacency_list[2]->next->end_vertex = 1;
    adjacency_list[2]->next->value = 3;
    adjacency_list[2]->next->next = (struct cell *)malloc(sizeof(struct cell));
    adjacency_list[2]->next->next->end_vertex = 3;
    adjacency_list[2]->next->next->value = 2;
    adjacency_list[2]->next->next->next =
        (struct cell *)malloc(sizeof(struct cell));
    adjacency_list[2]->next->next->next->end_vertex = 4;
    adjacency_list[2]->next->next->next->value = 3;
    adjacency_list[2]->next->next->next->next =
        (struct cell *)malloc(sizeof(struct cell));
    adjacency_list[2]->next->next->next->next->end_vertex = 5;
    adjacency_list[2]->next->next->next->next->value = 3;
    adjacency_list[2]->next->next->next->next->next = NULL;

    adjacency_list[3] = (struct cell *)malloc(sizeof(struct cell));
    adjacency_list[3]->end_vertex = 0;
    adjacency_list[3]->value = 4;
    adjacency_list[3]->next = (struct cell *)malloc(sizeof(struct cell));
    adjacency_list[3]->next->end_vertex = 1;
    adjacency_list[3]->next->value = 1;
    adjacency_list[3]->next->next = (struct cell *)malloc(sizeof(struct cell));
    adjacency_list[3]->next->next->end_vertex = 2;
    adjacency_list[3]->next->next->value = 2;
    adjacency_list[3]->next->next->next =
        (struct cell *)malloc(sizeof(struct cell));
    adjacency_list[3]->next->next->next->end_vertex = 4;
    adjacency_list[3]->next->next->next->value = 2;
    adjacency_list[3]->next->next->next->next =
        (struct cell *)malloc(sizeof(struct cell));
    adjacency_list[3]->next->next->next->next->end_vertex = 5;
    adjacency_list[3]->next->next->next->next->value = 5;
    adjacency_list[3]->next->next->next->next->next = NULL;

    adjacency_list[4] = (struct cell *)malloc(sizeof(struct cell));
    adjacency_list[4]->end_vertex = 2;
    adjacency_list[4]->value = 3;
    adjacency_list[4]->next = (struct cell *)malloc(sizeof(struct cell));
    adjacency_list[4]->next->end_vertex = 3;
    adjacency_list[4]->next->value = 2;
    adjacency_list[4]->next->next = (struct cell *)malloc(sizeof(struct cell));
    adjacency_list[4]->next->next->end_vertex = 5;
    adjacency_list[4]->next->next->value = 1;
    adjacency_list[4]->next->next->next = NULL;

    adjacency_list[5] = (struct cell *)malloc(sizeof(struct cell));
    adjacency_list[5]->end_vertex = 2;
    adjacency_list[5]->value = 3;
    adjacency_list[5]->next = (struct cell *)malloc(sizeof(struct cell));
    adjacency_list[5]->next->end_vertex = 3;
    adjacency_list[5]->next->value = 5;
    adjacency_list[5]->next->next = (struct cell *)malloc(sizeof(struct cell));
    adjacency_list[5]->next->next->end_vertex = 4;
    adjacency_list[5]->next->next->value = 1;
    adjacency_list[5]->next->next->next = NULL;
}

void from_list_to_matrix(struct cell *adjacency_list[N],
                         int adjacency_matrix[N][N]) {
    int i, j;
    struct cell *current;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            adjacency_matrix[i][j] = 0;
        }
        current = adjacency_list[i];
        while (current != NULL) {
            j = current->end_vertex;
            adjacency_matrix[i][j] = current->value;
            current = current->next;
        }
    }
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
}
