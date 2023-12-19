//
// 2023.10.31 1 main
//
#define K 10
#define N 11

#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]) {
    int k, n, m;

    int **triangle;
    int **malloc_pascal();
    void calc_pascal(int **traiangle);
    void free_pascal(int **traiangle);
    double calc_probability(int **triangle, int k,int n, int m);
    
    if(argc != 4){
        fprintf(stderr,"\nUsage: %s <k> <n> <m> \n\n",argv[0]);
        exit(1);
    }

    k = atoi(argv[1]);
    n = atoi(argv[2]);
    m = atoi(argv[3]);
    
    if(k < 0 || k > K || n < 0 || n > N-1 || m < 0 || m > n){
     fprintf(stderr,"\n k = %d, k must satisfy 0 <= k <= %d\n",k,K);
     fprintf(stderr,"\n n = %d, k must satisfy 0 <= n <= %d\n",n,N-1);
     fprintf(stderr,"\n k = %d, k must satisfy 0 <= m <= %d\n",m,n);
     exit(1);
    }
    triangle = malloc_pascal();
    calc_pascal(triangle);
    printf("Probability = %0.10f\n",calc_probability(triangle,k,n,m));
    free_pascal(triangle);

    return 0;
}

int **malloc_pascal() {
    int **pascal;
    int i;

    if ((pascal = (int **)malloc(sizeof(int *) * N)) == NULL) {
        fprintf(stderr, "Error: failure in malloc()\n");
        exit(1);
    }
    for (i = 0; i < N; i++) {
        if ((pascal[i] = (int *)malloc(sizeof(int) * (i + 1))) == NULL) {
            fprintf(stderr, "Error: failure in malloc()\n");
            exit(1);
        }
    }

    return pascal;
}

void calc_pascal(int **triangle) {
    int i, j;

    for (i = 0; i < N; i++) {
        triangle[i][0] = triangle[i][i] = 1;
    }

    for (i = 0; i < N; i++) {
        for (j = 1; j < i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }
}

void free_pascal(int **triangle) {
    int i;

    for (i = 0; i < N; i++) {
        free(triangle[i]);
    }
    free(triangle);
}

double calc_probability(int **triangle, int k,int n, int m){
    double p;
    int i;
    int nCm(int n,int m);

     p = nCm(n,m);

    for(i = 0;i < m;i++){
        p *= k/10.0;
    }
    for(i = 0;i < n-m;i++){
        p *= (10-k)/10.0;
    }
    return p;
}

int nCm(int n,int m){
    int factrial(int n);
    return factrial(n)/factrial(m)/factrial(n-m);
}

int factrial(int n){
    int f = 1;
    int i;

    for(i = 1;i <= n;i++){
        f *= i;
    }

    return f;
}

