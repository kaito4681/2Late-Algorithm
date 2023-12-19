//
//2023/12/05 B main
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define MAX 10
void push_heap(int list[], int n);
int delete_minimum(int list[],int n);
void downheap(int list[], int n);



int main(void) {
  int A[N];
  int i,j;

  srandom(time(NULL));
  
  A[0] =  random() % MAX;

  for (i = 1; i < N; i++) {
    A[i] =  random() % MAX;
    push_heap(A,i);
  }
  printf("A = ");
  for (j = 0; j < N  ; j++) printf("%d ", A[j]);
  for (i = N - 1; i > -1; i--) {
    printf("\ndelete %d\t", delete_minimum(A,i));
    printf("A = ");
    for (j = 0; j < i ; j++) printf("%d ", A[j]);
  }
  printf("\n");
  return 0;
}

int delete_minimum(int list[], int n){
  int min;
  min = list[0];
  list[0] = list[n];
  downheap(list,n);
  return min;
}

void downheap(int list[], int n){
  int val, l, i;

  val = list[0];
  i = 0;

  while(i <= (n + 1) / 2 - 1){
    l = (i + 1) * 2 -1;
    if((l < n) && (list[l] > list[l + 1])){
      l++;
    }
    if(val <= list[l]){
      break;
    }
    list[i] = list[l];
    i = l;
  }
  list[i] = val;
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