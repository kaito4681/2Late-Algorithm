//
//2024.01.23 A main
//
#include <stdio.h>
#include <stdlib.h>
#define N 5

int main(int argc, char *argv[]){
  double A[N] = {3.0,1.0,2.0,4.0,1.0};
  double alpha;
  double Horner(double* A, double alpha, int i);

  if(argc != 2){
    printf("Input one real number:\n");
    exit(1);
  }
  alpha = atof(argv[1]);
  printf("f(%lf) = %lf\n",alpha,Horner(A,alpha,0));
  return 0;
}


double Horner(double* A, double alpha, int i){
  int j;
  
  if(i ==  N -1){
    return A[i];
  }else {
    j = i;
    i++;
    return Horner(A, alpha, i) * alpha + A[j]; 
  }
}
