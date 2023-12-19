//
// 2023.11.28 3 main
//
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <time.h>

#define N 30000

int check_array(int *D, int num);
double sorting_time(struct rusage *ru1, struct rusage *ru2);
int partition(int *D, int left, int right);
void quick_sortA(int D[], int left, int right);

int main() {
    int *D, i;
    struct rusage ru1, ru2;

    if (NULL == (D = malloc(sizeof(int) * N))) {
        printf("No more memory\n");
        exit(1);
    }

    srandom(time(NULL));
    for (i = 0; i < N; i++) D[i] = random();
    printf("Make random memory\n");

    getrusage(RUSAGE_SELF, &ru1);
    quick_sortA(D, 0, N - 1);
    getrusage(RUSAGE_SELF, &ru2);

    if (check_array(D, N) == 1) {
        printf("selection_sort(First) :%10.6lf\n", sorting_time(&ru1, &ru2));
    }

    getrusage(RUSAGE_SELF, &ru1);
    quick_sortA(D, 0, N - 1);
    getrusage(RUSAGE_SELF, &ru2);
    printf("selection_sort(Second) :%10.6lf\n", sorting_time(&ru1, &ru2));

    return 0;
}

int check_array(int *D, int num) {
    int i;
    for (i = 1; i < num; i++) {
        if (D[i - 1] > D[i]) {
            return 0;
        }
    }
    return 1;
}

double sorting_time(struct rusage *ru1, struct rusage *ru2) {
    double time1, time2;
    time1 = (ru1->ru_utime).tv_sec + (ru1->ru_utime).tv_usec / 1000000.0;
    time2 = (ru2->ru_utime).tv_sec + (ru2->ru_utime).tv_usec / 1000000.0;
    return time2 - time1;
}

void swap(int D[], int i, int j) {
    int temp;
    temp = D[i];
    D[i] = D[j];
    D[j] = temp;
}

int partition(int D[], int left, int right) {
    int i, j, pivot_index;

    pivot_index = (left + right) / 2;
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
    return i;
}

void quick_sortA(int D[], int left, int right) {
    int pivot_index;
    pivot_index = partition(D, left, right);
    if (left < pivot_index - 1) quick_sortA(D, left, pivot_index - 1);
    if (pivot_index + 1 < right) quick_sortA(D, pivot_index + 1, right);
}