//
//2023.11.28 C main
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>

#define N 16

void merge_sort(int D[N], int left, int right);
void merge(int D[], int left,int mid, int right);
void print_array(int D[]);


int main(){
  int D[N],i;

  srandom(time(NULL));
  for(i = 0; i < N; i++) D[i] = random() % 100;
  printf("The original sequence: \t"); print_array(D);
  merge_sort(D,0,N-1);
  printf("\nThe final sequence: \t"); print_array(D);
  return 0;
}

void print_array(int D[]){
  int i;
  for(i = 0; i < N ; i++) printf("%2d " , D[i]);
  printf("\n");
}


void merge_sort(int D[N], int left, int right){
  int mid;

  mid = (left + right) /2;
  if( left < mid) merge_sort(D, left,mid);
  if(mid+1 < right) merge_sort(D,mid+1,right);
  printf("(left,right)=(%2d,%2d): \t",left,right);
  merge(D,left,mid,right);
}

void merge(int D[],int left ,int mid, int right){
  int temp[N];int i , x, y;

  x = left;
  y = mid+1;
  for(i = left; i <= right; i++){
    if(x == mid + 1){
      temp[i-left] = D[y];
      y++;
    }else if(y == right+ 1){
      temp[i-left] = D[x];
      x++;
    }else if(D[x] <= D[y]){
      temp[i-left] = D[x];
      x++;
    }else{
      temp[i-left] = D[y];
      y++;
    }
  }
  
  for(i = left; i <= right; i++){
    D[i] = temp[i-left];
  }
  print_array(D);
}