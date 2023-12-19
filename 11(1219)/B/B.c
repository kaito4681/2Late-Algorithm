//
//2023.12.19 B main
//
#include <stdio.h>
#include <stdlib.h>

void recursive(int level, int n, int *binary);

int main(int argc, char **argv){
  int n;
  int * binary;

  if(argc == 1){
    fprintf(stderr,"\nUsage : %s input integer.\n",argv[0]);
    exit(1);
  }

  n = atoi(argv[1]);
  binary = malloc(sizeof(int) * n);
  recursive(0,n,binary);

  return 0;
}


void recursive(int level, int n, int *binary){
  int max = 1;
  int i,j,k;

  for(i = 0; i < n; i++){
    max *= 2;
  }
  max -= 1;
  
  for(i = 0; i <= max ; i++){
    k= i;
    for(j = 0; j < n; j++){
      binary[j] = k % 2;
      k /= 2;
    }
    
    for(j = n - 1; j >= 0; j--){
      if(binary[j] == 0){
	printf("0");
      }else{
	printf("1");
      }
    }
    printf("\n");
  }
  
}

  
