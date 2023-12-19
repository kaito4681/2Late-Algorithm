//
//2023.11.28 B main
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>

#define N 10

int main(){
  int D[N],i;
  void insertion_sort(int D[],int n);

  srandom(time(NULL));
  for(i = 0; i < N; i++) D[i] = random() % 100;
  for(i = 0; i < N; i++) printf("%d ",D[i]);
  printf("\n");
  insertion_sort(D,N);
  return 0;
}

void insertion_sort(int D[], int n){
    int i, j, t;

    for(i = 1; i < n ;i++){
      t = D[i];
      j = i;
      while((D[j-1] > t) && (j > 0)){
	D[j] = D[j-1];
	j--;
      }
      D[j] = t;
      
      for(j = 0; j < n; j++){
	printf("%d ",D[j]);
      }
    printf("\n");
    }

}