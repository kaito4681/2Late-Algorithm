//
// 2023.12.19 1 main
//
#include <stdio.h>
#include <stdlib.h>

void BT_subsetsum(int level, int n, int total, int *X, int *Y);

int main(int argc, char **argv) {
    int i, n, total;
    int *X;
    int *Y;

    if (argc == 1) {
        fprintf(stderr, "\nUsage : %s input integer.\n", argv[0]);
        exit(1);
    }

    n = argc - 2;
    printf("n=%d, ", n);
    X = malloc(sizeof(int) * n);
    Y = malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        X[i] = atoi(argv[i + 1]);
        printf("X[%d]=%d ", i, X[i]);
    }

    printf("\n");
    total = atoi(argv[argc - 1]);
    printf("total=%d\n", total);

    BT_subsetsum(0, n, total, X, Y);
}

void BT_subsetsum(int level, int n, int total, int *X, int *Y) {
    int sum, sum1, sum2, i, j;
    //  static int f = 0;  // sumをみつけたら1

    if (level + 1 > n) {
        sum = 0;
        for (i = 0; i < n; i++) {
            sum += Y[i] * X[i];
        }
        if (sum == total) {
            printf("Sum of");
            for (j = 0; j < n; j++) {
                if (Y[j] == 1) {
                    printf(" %d", X[j]);
                }
            }
            printf(" is %d", total);
            printf("\n");
        }
    } else {
        sum1 = 0;
        sum2 = 0;
        for (i = 0; i < n; i++) {
            if (i < level + 1) {
                sum1 += Y[i] * X[i];
                sum2 = sum1;
            } else {
                sum2 += X[i];
            }
        }

        if (sum1 <= total && sum2 >= total) {
            Y[level] = 0;
            BT_subsetsum(level + 1, n, total, X, Y);
            Y[level] = 1;
            BT_subsetsum(level + 1, n, total, X, Y);
        }
    }
}
