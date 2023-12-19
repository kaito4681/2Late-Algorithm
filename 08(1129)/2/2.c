//
// 2023.11.28 2 main
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 9

int partition(int *D, int left, int right);
void quick_sortA(int D[], int left, int right);
void print_array(int D[]);

int main() {
    int D[N], i;
    srandom(time(NULL));
    // for (i = 0; i < N; i++) D[i] = N - i - 1;
    // for (i = 0; i < N; i++) D[i] = i + 10;
    for (i = 0; i < N; i++) D[i] = random() % 10;
    printf("The original sequence: \t");
    print_array(D);
    quick_sortA(D, 0, N - 1);
    printf("\nThe final sequence: \t");
    print_array(D);

    return 0;
}

void swap(int D[], int i, int j) {
    int temp;

    printf("swap(D[%d]=%d,D[%d]=%d),D=\t", i, D[i], j, D[j]);
    temp = D[i];
    D[i] = D[j];
    D[j] = temp;
    print_array(D);
}

void print_array(int D[]) {
    int i;
    for (i = 0; i < N; i++) {
        printf("%d ", D[i]);
    }
    printf("\n");
}

int partition(int D[], int left, int right) {
    int i, j, pivot_index;

    pivot_index = (left + right) / 2;
    printf("left = %d, right = %d, pivot_index = %d, pivot = %d\n", left, right,
           pivot_index, D[pivot_index]);
    swap(D, pivot_index, right);
    pivot_index = right;
    i = left;
    j = right - 1;
    while (1) {
        while (D[i] < D[pivot_index]) i++;
        while ((i < j) && (D[pivot_index] <= D[j])) j--;
        if (i >= j) break;
        swap(D, i, j);
    }
    swap(D, i, pivot_index);
    printf("return pivot_index = %d\n", i);
	return i;
}

void quick_sortA(int D[], int left, int right) {
    int pivot_index;
    pivot_index = partition(D, left, right);
    if (left < pivot_index - 1) quick_sortA(D, left, pivot_index - 1);
    if (pivot_index + 1 < right) quick_sortA(D, pivot_index + 1, right);
}