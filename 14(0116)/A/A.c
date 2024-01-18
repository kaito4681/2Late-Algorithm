//
//2024.01.16 1 main
//
#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b);

int main(int argc, char *argv[]){
  int a,b;

  if(argc != 3){
    printf("Input 2 intergers\n");
    exit(1);
  }
  
  a = atoi(argv[1]);
  b = atoi(argv[2]);

  printf("gcd(%d,%d)=%d\n", a,b,gcd(a,b));

  return 0;
}

int gcd(int a, int b){
  int ans = 1, i, c;

  if(a >= b){
    c = b;
  }else{
    c = a;
  }

  for(i = 2; i <= c; i++){
    if(a % i == 0 && b % i == 0){
      ans = i;
    }
  }

  return ans;
}
