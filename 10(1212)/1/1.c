//
//2023 12.12 main
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>

#define N 50000

int check_array(int *array, int num);
double sorting_time(struct rusage *ru1, struct rusage *ru2);
int compare_int (const void *a, const void *b);		    

int main() {
    int D[N], i;
    struct rusage ru1, ru2;
    
    srandom(time(NULL));
    for (i = 0; i < N; i++) D[i] = random() % 100;
    getrusage(RUSAGE_SELF, &ru1);
    qsort(D,N,sizeof(int),compare_int);
    getrusage(RUSAGE_SELF, &ru2);
    if (check_array(D, N) == 1) {
      printf("qsort(First) :%10.6lf\n", sorting_time(&ru1, &ru2));
    }

    getrusage(RUSAGE_SELF, &ru1);
    qsort(D,N,sizeof(int),compare_int);
    getrusage(RUSAGE_SELF, &ru2);
    if (check_array(D, N) == 1) {
      printf("qsort(Second) :%10.6lf\n", sorting_time(&ru1, &ru2));
    }
    
    return 0;
}

int compare_int (const void *a, const void *b){
  return *(int*)a - *(int*)b;
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
