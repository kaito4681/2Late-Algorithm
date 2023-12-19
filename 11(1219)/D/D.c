//
//2023.12.19 D main
//
#include <stdio.h>
#include <stdlib.h>

void BT_subsetsum( int n, int total, int *X, int *Y);

int main(int argc, char **argv){
  int i, n, total;
  int *X;
  int *Y;

  if(argc == 1){
    fprintf(stderr,"\nUsage : %s input integer.\n",argv[0]);
    exit(1);
  }

  n = argc - 2;
  printf("n=%d, ",n);
  X  = malloc(sizeof(int) * n);
  Y  = malloc(sizeof(int) * n);  
  
  for(i = 0; i < n ; i++){
    X[i] = atoi(argv[i+1]);
    printf("X[%d]=%d ",i,X[i]);
  }

  printf("\n");
  total = atoi(argv[argc-1]);
  printf("total=%d\n", total);

  BT_subsetsum(n,total,X,Y);
}
  


void BT_subsetsum(int n, int total, int *X, int *Y){
  int max = 1;
  int i,j,k,sum;

  for(i = 0; i < n; i++){
    max *= 2;
  }
  max -= 1;
  
  for(i = 0; i <= max ; i++){
    k= i;
    for(j = 0; j < n; j++){
      Y[j] = k % 2;
      k /= 2;
    }
    sum = 0;
    for(j = 0; j < n; j++){
      sum += X[j] * Y[j]; 
    }
    if(sum == total){
      printf("Sum of");
      for(k = 0; k < n; k++){
		if(Y[k] == 1){
	  	printf(" %d",X[k]);
		}
      }
	  printf(" is %d", total);
      printf("\n");
      return;
    }
  }
  printf("There is no sebset whose sum is %d\n",total);
  return;
}
