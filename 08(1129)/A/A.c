//
//2023.11.28
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>

#define N 10

int main(){
  int D[N],i;
  void selection_sort(int D[],int n);

  srandom(time(NULL));
  for(i = 0; i < N; i++) D[i] = random() % 100;
  for(i = 0; i < N; i++) printf("%d ",D[i]);
  printf("\n");
  selection_sort(D,N);
  return 0;
}

void selection_sort(int D[], int n){
    int i, j, t, max, maxpos;
    for (i = n-1; i >0; i--) {
        maxpos = i;
        max = D[maxpos];
        for (j = 0; j < i; j++) {
            if (max < D[j]) {
                maxpos = j;
                max = D[maxpos];
            }
        }
        t = D[i];
        D[i] = D[maxpos];
        D[maxpos] = t;

	for(j = 0; j < n; j++){
	  printf("%d ",D[j]);
	}
	printf("\n");
    }
}