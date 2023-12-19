//
// 2023.12.12 D main
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4
#define C 4

struct dp_table {
    int value;
    int S[N];
};

void initialize_table(struct dp_table table[N][C + 1]);
void dp_table(int W[N], int V[N], struct dp_table table[N][C + 1]);
void print_table(struct dp_table table[N][C + 1]);

int main() {
    int i;
    int W[N] = {30,10,30,20}, V[N] = {20,10,40,50};
    struct dp_table table[N][C + 1];

    srandom(time(NULL));

    for (i = 0; i < N; i++) {
        printf("W[%d] = %d, V[%d] = %3d\n", i, W[i], i, V[i]);
    }
    printf("C=%d\n", C*10);

    initialize_table(table);
    dp_table(W, V, table);
    print_table(table);
    return 0;
}

void initialize_table(struct dp_table table[N][C + 1]) {
    int i, j, k;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++) {
            table[i][j].value = 0;
            for (k = 0; k < N; k++) table[i][j].S[k] = 0;
        }
}

void dp_table(int W[N], int V[N], struct dp_table table[N][C + 1]) {
    int i, j, k, v1, v2;

    for (j = 0; j < C + 1; j++) {
        if (10*j >= W[0]) {
            table[0][j].value = V[0];
            table[0][j].S[0] = 1;
        } else {
            table[0][j].value = 0;
            table[0][j].S[0] = 0;
        }
    }

    for (i = 1; i < N; i++) {
        for (j = 0; j < C + 1; j++) {
            if (j >= W[i]/10) {
                v1 = table[i - 1][j].value;
                v2 = table[i - 1][j - W[i]/10].value + V[i];

                if (v1 >= v2) {
                    table[i][j].value = v1;
                    for (k = 0; k < N; k++) {
                        table[i][j].S[k] = table[i - 1][j].S[k];
                    }
                } else {
                    table[i][j].value = v2;
                    for (k = 0; k < N; k++) {
                        table[i][j].S[k] = table[i - 1][j-W[i]/10].S[k];
                    }
                    table[i][j].S[i] = 1;
                }
            } else {
                table[i][j].value = table[i - 1][j].value;
                for (k = 0; k < N; k++) {
                    table[i][j].S[k] = table[i - 1][j].S[k];
                }
            }
        }
    }
}

void print_table(struct dp_table table[N][C + 1]) {
    int i, j, k;

    for (i = 0; i < N; i++) {
        for (j = 0; j < C + 1; j++) {
            printf("[%3d:{", table[i][j].value);
            for (k = 0; k < N; k++) {
                if (table[i][j].S[k] == 1) {
                    printf("%d,", k);
                }
            }
            printf("}] ");
        }
        printf("\n");
    }
}
