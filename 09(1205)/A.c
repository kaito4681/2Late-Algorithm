//
//2023/12/05
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define MAX 10
void push_heap(int list[], int n);


int main(void) {
  int A[N];
  int i,j;

  srandom(time(NULL));
  
  A[0] =  random() % MAX;

  for (i = 1; i < N; i++) {
    A[i] =  random() % MAX;
    printf("\nA = ");
    for (j = 0; j <= i; j++) printf("%d ", A[j]);
    push_heap(A,i);
    printf("\nA = ");
    for (j = 0; j <= i; j++) printf("%d ", A[j]);
    printf("\n");
  }
  return 0;
}

void push_heap(int list[], int n){
  int val,i;
  val =  list[n];
  while(n > 0){
    i = (n + 1) / 2 - 1;
    if(list[i] > val){
      list[n] = list[i];
    }else{
      break;
    }
    n = i;
  }
  list[n] = val;
}