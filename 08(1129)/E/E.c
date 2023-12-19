// //
// // 2023.11.28 E main
//
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <time.h>

#define N 30000

int main() {
    int *D, i;
    struct rusage ru1, ru2;

    int check_D(int *D, int num);
    double sorting_time(struct rusage * ru1, struct rusage * ru2);
    void selection_sort(int D[], int n);

    if (NULL == (D = malloc(sizeof(int) * N))) {
        printf("No more memory\n");
        exit(1);
    }

    srandom(time(NULL));
    for (i = 0; i < N; i++) D[i] = random() % 100;
    printf("Make random memory\n");

    getrusage(RUSAGE_SELF, &ru1);
    selection_sort(D, N);
    getrusage(RUSAGE_SELF, &ru2);

    if (check_D(D, N) == 1) {
        printf("selection_sort(First) :%10.6lf\n", sorting_time(&ru1, &ru2));
    }
    
    getrusage(RUSAGE_SELF, &ru1);
    selection_sort(D, N);
    getrusage(RUSAGE_SELF, &ru2);

    if (check_D(D, N) == 1) {
        printf("selection_sort(Second) :%10.6lf\n", sorting_time(&ru1, &ru2));
    }

    return 0;
}

int check_D(int *D, int num) {
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

void selection_sort(int D[], int n) {
    int i, j, t, max, maxpos;
    for (i = n - 1; i > 0; i--) {
        maxpos = i;
        max = D[maxpos];
        for (j = 0; j < i; j++) {
            if (max < D[j]) {
                maxpos = j;
                max = D[maxpos];
            }
        }
        t = D[i];
        D[i] = D[maxpos];
        D[maxpos] = t;
    }
}
