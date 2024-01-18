//
//2024.01.16 B main
//
#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n);

int main(int argc, char *argv[]) {
  int n,i;
  int F[40];

  if (argc != 2) {
    fprintf(stderr, "\nUsage : %s positive_integer <= 40\n\n", argv[0]);
    exit(1);
  }
  
  n = atoi(argv[1]);

  if (n >= 41) {
    fprintf(stderr, "\nUsage : %s positive_integer <= 40\n\n", argv[0]);
    exit(1);
  }else if(n == 0){
    printf("Fibonacci(0) = 0\n");
  }else if(n == 1){
    printf("Fibonacci(1) = 1\n");
  }else if(n >= 2){
    F[0] = 0;
    F[1] = 1;
    for(i = 2; i <= n; i++){
      F[i] = F[i-1] + F[i-2];
    }
    
    printf("Fibonacci(%d) = %d\n",n, F[n]);
  }
  return 0;
}


