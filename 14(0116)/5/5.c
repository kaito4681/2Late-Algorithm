#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

void print_size(int matrix_row[N], int matrix_column[N]) {
    for (int i = 0; i < N; i++) {
        printf("M_%d: %d x %d\n", i, matrix_row[i], matrix_column[i]);
    }
}

int min(int a, int b) {
    return a < b ? a : b;
}

void multiplication(int matrix_row[N], int matrix_column[N]) {
    int min_cost[N][N], split[N][N];
    int i, left, right, length, cost, choice;

    for (i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            min_cost[i][j] = INT_MAX;
        }
    }

    for (i = 0; i < N - 1; i++) {
        min_cost[i][i + 1] = matrix_row[i] * matrix_column[i] * matrix_column[i + 1];
        split[i][i + 1] = i;
    }

    for (length = 2; length < N; length++) {
        for (left = 0; left < N - length; left++) {
            right = left + length;

            for (choice = left; choice < right; choice++) {
                cost = min_cost[left][choice] + min_cost[choice + 1][right] +
                       matrix_row[left] * matrix_column[choice] * matrix_column[right];

                if (cost < min_cost[left][right]) {
                    min_cost[left][right] = cost;
                    split[left][right] = choice;
                }
            }
        }
    }

    for (length = 1; length < N; length++) {
        for (left = 0; left < N - length; left++) {
            printf("From %d to %d = %d (choice = %d)\n", left, left + length,
                   min_cost[left][left + length], split[left][left + length]);
        }
    }
    printf("\nMinimum cost = %d\n", min_cost[0][N - 1]);

    print_calculation_order(split, 0, N - 1);
    printf("\n");
}

void print_calculation_order(int split[N][N], int front, int end) {
    if (front == end) {
        printf(" M_%d ", front);
    } else {
        printf("(");
        print_calculation_order(split, front, split[front][end]);
        print_calculation_order(split, split[front][end] + 1, end);
        printf(")");
    }
}

int main() {
    int matrix_row[N], matrix_column[N];

    srandom(time(NULL));
    initialization(matrix_row, matrix_column);

    print_size(matrix_row, matrix_column);
    multiplication(matrix_row, matrix_column);

    return 0;
}

void initialization(int matrix_row[N], int matrix_column[N]) {
    matrix_row[0] = random() % 7 + 2;

    for (int i = 0; i < N - 1; i++) {
        matrix_column[i] = random() % 7 + 2;
        matrix_row[i + 1] = matrix_column[i];
    }

    matrix_column[N - 1] = random() % 7 + 2;
}
