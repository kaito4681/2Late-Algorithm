//
//2023.10.10 4.c
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 3

void initialize(int a[N][N],int B[N][N]);
void print_matrix(int matrix[N][N]);
void multiply(int A[N][N], int B[N][N],int C[N][N]);


int main(){
  int A[N][N], B[N][N], C[N][N];
  
  srandom(time(NULL));
  
  initialize(A,B);
  printf("A = \n");
  print_matrix(A);
  printf("B = \n");
  print_matrix(B);

  multiply(A,B,C);
  printf("A*B=\n");
  print_matrix(C);

  return 0;
}

      
void initialize(int A[N][N],int B[N][N]){
  int i,j;

  for(i = 0;i < N ; i++){
    for(j = 0 ; j < N ; j++){
      A[i][j] = random() % 10;
      B[i][j] = random() % 10;
    }
  }
}

void print_matrix(int matrix[N][N]){
  int i,j;
  
  for(i = 0;i < N ; i++){
    for(j = 0 ; j < N ; j++){
      printf("%3d ",matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}


void multiply(int A[N][N], int B[N][N],int C[N][N]){
  int i,j,k;
  
  for(i = 0;i < N ; i++){
    for(j = 0 ; j < N ; j++){
      for(k = 0 ; k < N ; k++){
	C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}
