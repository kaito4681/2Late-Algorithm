//
// 2023.11.28 D main
//
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <time.h>

#define N 20

void merge_sort3(int D[N], int left, int right);
void merge(int D[], int left, int p1, int p2, int right);
void print_array(int D[]);

int main() {
    int D[N], i;

    srandom(time(NULL));
    for (i = 0; i < N; i++) D[i] = random() % 100;
    printf("The original sequence: \t");
    print_array(D);
    merge_sort3(D, 0, N - 1);
    printf("\nThe final sequence: \t");
    print_array(D);
    return 0;
}

void print_array(int D[]) {
    int i;
    for (i = 0; i < N; i++) printf("%2d ", D[i]);
    printf("\n");
}

void merge_sort3(int D[N], int left, int right) {
    int p1, p2;

    p1 = left + (right - left + 1) / 3;
    p2 = p1 + (right - left + 1) / 3;
    if (left < p1) merge_sort3(D, left, p1);
    if (p1 + 1 < p2) merge_sort3(D, p1 + 1, p2);
    if (p2 + 1 < right) merge_sort3(D, p2 + 1, right);

    printf("(left,p1,p2,right)=(%2d,%2d,%2d,%2d): \t", left, p1, p2, right);
    merge(D, left, p1, p2, right);
}

void merge(int D[], int left, int p1, int p2, int right) {
    int temp[N];
    int i, x, y, z;

    x = left;
    y = p1 + 1;
    z = p2 + 1;

    for (i = 0; i <= right - left; i++) {
        if (x <= p1 && (y > p2 || D[x] <= D[y]) &&
            (z > right || D[x] <= D[z])) {
            temp[i] = D[x];
            x++;
        } else if (y <= p2 && (z > right || D[y] <= D[z])) {
            temp[i] = D[y];
            y++;
        } else {
            temp[i] = D[z];
            z++;
        }
    }

    for (i = 0; i <= right - left; i++) {
        D[left + i] = temp[i];
    }
    print_array(D);
}
