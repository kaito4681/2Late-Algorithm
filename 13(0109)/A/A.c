//
//2024.01.09 A main
//
#include <stdio.h>
#include <stdlib.h>
#define N 5

int main(int argc, char *argv[]){
  double A[N] = {3.0,1.0,2.0,4.0,1.0};
  double alpha;
  double Horner(double* A, double alpha);

  if(argc != 2){
    printf("Input one real number:\n");
    exit(1);
  }
  alpha = atof(argv[1]);
  printf("f(%lf) = %lf\n",alpha,Horner(A,alpha));
  return 0;
}


double Horner(double* A, double alpha){
  int i;
  double ans;

  ans = A[N-1];

  for(i = 1; i < N ; i++){
    ans = ans * alpha + A[N - 1 - i];
  }

  return ans;
}
