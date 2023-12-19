//
//2023.10.10 2.c
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv){
  int *B;
  int n = argc,i,d;

  //Usage
  if(argc < 2){  
    fprintf(stderr,"Input Binary sequence,for example 1 0 1 1\n");
    exit(1);
  }
  
  //malloc
  if((B = (int *)malloc(sizeof(int) * n)) == NULL){
    fprintf(stderr,"\nError : failure in malloc\n\n");
    exit(1);
  }

  for(i = 1; i < n ; i++){
    B[i] = atoi(argv[i]);
    if( B[i] != 0 && B[i] != 1){
      fprintf(stderr,"Input Binary sequence, for example 1 0 1 1 \n");
      exit(1);
    }
    printf("%d ",B[i]);
  }
  printf("\n");

  d = B[1];
  for(i = 2; i < n ; i++){
    d=d*2+B[i];
  }
  
  printf("answer = %d\n",d);
  
  free(B);
  return 0;
}

      