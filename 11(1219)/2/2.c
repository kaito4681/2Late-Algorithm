//
// 2023.12.19 2 main
//
#include <stdio.h>
#include <stdlib.h>

int dp_subsetsum(int n, int total, int *X);

int main(int argc, char **argv) {
    int i, n, total;
    int *X;

    if (argc == 1) {
        fprintf(stderr, "\nUsage : %s input integer and one sum of subset.\n",
                argv[0]);
        exit(1);
    }

    n = argc - 2;
    printf("n=%d\t", n);
    X = malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        X[i] = atoi(argv[i + 1]);
        printf("X[%d]=%d, ", i, X[i]);
    }

    printf("\t");
    total = atoi(argv[argc - 1]);
    printf("total=%d\n", total);

    if (dp_subsetsum(n, total, X) == 1) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}

int dp_subsetsum(int n, int total, int *X) {
    int table[n][total + 1];
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j <= total; j++) {
            table[i][j] = 0;
        }
        table[0][0] = 0;
    }

    if (X[0] <= total) {
        table[0][X[0]] = 1;
    }

    for (i = 1; i < n; i++) {
        for (j = 0; j <= total; j++) {
            if (j > X[i]) {
                table[i][j] = table[i - 1][j - X[i]];
            } else if (j == X[i]) {
                table[i][j] = 1;
            }
        }
    }

    if (table[n - 1][total] == 1) {
        return 1;
    } else {
        return 0;
    }
}
