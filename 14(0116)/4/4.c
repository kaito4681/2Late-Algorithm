#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

void print_size(int row[N], int column[N]);
void initialization(int row[N], int column[N]);
void multiplication(int row[N], int column[N]);
void print_calculation_order(int split[N][N], int front, int end);

int main() {
    int row[N], column[N];

    srandom(time(NULL));
    initialization(row, column);

    print_size(row, column);
    multiplication(row, column);

    return 0;
}

void initialization(int row[N], int column[N]) {
    row[0] = random() % 7 + 2;

    for (int i = 0; i < N - 1; i++) {
        column[i] = random() % 7 + 2;
        row[i + 1] = column[i];
    }

    column[N - 1] = random() % 7 + 2;
}

void print_size(int row[N], int column[N]) {
    for (int i = 0; i < N; i++) {
        printf("M_%d: %d x %d\n", i, row[i], column[i]);
    }
}

void multiplication(int row[N], int column[N]) {
    int min(int a, int b);

    int mincost[N][N], split[N][N];
    int i, left, right, length, cost, choice;

    // mincost[i][i + 1] の初期化と計算を分離する
    for (i = 0; i < N - 1; i++) {
        mincost[i][i + 1] = 0;

        for (i = 0; i < N - 1; i++) {
            split[i][i + 1] = i;
        }

        for (i = 0; i < N - 1; i++) {
            mincost[i][i + 1] = row[i] * column[i] * column[i + 1];
            split[i][i + 1] = i;
        }

        for (length = 2; length < N; length++) {
            for (left = 0; left < N - length; left++) {
                right = left + length;
                mincost[left][right] = INT_MAX;

                for (choice = left; choice < right; choice++) {
                    cost = mincost[left][choice] + mincost[choice + 1][right] +
                           row[left] * column[choice] * column[right];

                    if (cost < mincost[left][right]) {
                        mincost[left][right] = cost;
                        split[left][right] = choice;
                    }
                }
            }
        }

        for (length = 1; length < N; length++) {
            for (left = 0; left < N - length; left++) {
                printf("From %d to %d = %d (choice = %d)\n", left,
                       left + length, mincost[left][left + length],
                       split[left][left + length]);
            }
        }
    }
    printf("\nMinimum cost = %d\n", mincost[0][N - 1]);

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
