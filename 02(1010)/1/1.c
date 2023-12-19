//
//2023.10.10 2.c
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv){
  int *B;
  int n = argc,i,j,d,p;
  
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
    printf("%d ",B[i]);
  }
  printf("\n");

  d = 0;
  n--;
  for(i = 1; i <=n ; i++){
    p = 1; j = i;
    while(j<n){
      p = p*2;
      j++;
    }
    d = d+B[i]*p;
  }

  printf("answer = %d\n",d);
  free(B);
  
  return 0;
}

      