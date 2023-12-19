//
// 2023.11.28 1 main
//
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <time.h>

#define N 30000

int main() {
    int *array, i;
    struct rusage ru1, ru2;

    int check_array(int *array, int num);
    double sorting_time(struct rusage * ru1, struct rusage * ru2);
    void insertion_sort(int list[], int n);

    if (NULL == (array = malloc(sizeof(int) * N))) {
        printf("No more memory\n");
        exit(1);
    }

    srandom(time(NULL));
    for (i = 0; i < N; i++) array[i] = random() % 100;
    printf("Make random memory\n");

    getrusage(RUSAGE_SELF, &ru1);
    insertion_sort(array, N);
    getrusage(RUSAGE_SELF, &ru2);

    if (check_array(array, N) == 1) {
        printf("selection_sort(First) :%10.6lf\n", sorting_time(&ru1, &ru2));
    }

    getrusage(RUSAGE_SELF, &ru1);
    insertion_sort(array, N);
    getrusage(RUSAGE_SELF, &ru2);

    if (check_array(array, N) == 1) {
        printf("selection_sort(Second) :%10.6lf\n", sorting_time(&ru1, &ru2));
    }

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
void insertion_sort(int D[], int n) {
    int i, j, t;

    for (i = 1; i < n; i++) {
        t = D[i];
        j = i;
        while ((D[j - 1] > t) && (j > 0)) {
            D[j] = D[j - 1];
            j--;
        }
        D[j] = t;
    }
}