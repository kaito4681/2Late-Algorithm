//
//2024.01.16 C main
//
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#define N 5

void print_size(int row[N], int column[N]);
void initialization(int row[N], int column[N]);
void multiplication(int row[N], int column[N]);

int main(){
  int row[N], column[N];
  srandom(time(NULL));
  initialization(row,column);
  print_size(row,column);
  multiplication(row,column);
  
  return 0;
}

void initialization(int row[N], int column[N]){
  int i;

  row[0] = random() % 7 + 2;
  for(i = 0; i < N-1; i++){
    column[i] = random() % 7 + 2;
    row[i+1] = column[i];
  }
  column[N-1] = random() % 7 + 2;
}

void print_size(int row[N], int column[N]){
  int i;

  for(i = 0; i < N; i++){
    printf("M_%d: %d x %d\n",i,row[i], column[i]);
  }
}

void multiplication(int row[N], int column[N]){
  int min(int a, int b);
  int i,left,length;
  int mincost[N+1][N+1];

  for(i = 0; i <= N-2; i++){  
    mincost[i][i + 1] = row[i] * column[i] * column[i + 1];
  }

  for(i = 0; i <= N-3; i++){  
    mincost[i][i + 2] = min(mincost[i+1][i+2] + row[i] * column[i] * column[i + 2], mincost[i][i+1] + row[i] * column[i+1] * column[i + 2]);
  }

  for(i = 0; i <= N-4; i++){  
    mincost[i][i + 3] = min(min(mincost[i+1][i+3] + row[i] * column[i] * column[i + 3],
				mincost[i][i+1] + mincost[i+2][i+3]  + row[i] * column[i+1] * column[i + 3]),
			    mincost[i][i+2] + row[i] * column[i+2] * column[i + 3]);
  }
  
  for(i = 0; i <= N-5; i++){  
    mincost[i][i + 4] = min(min(min(mincost[i+1][i+4] + row[i] * column[i] * column[i + 4],
				mincost[i][i+1] + mincost[i+2][i+4]  + row[i] * column[i+1] * column[i + 4]),
			    	mincost[i][i+2] + mincost[i+3][i+4]  + row[i] * column[i+2] * column[i + 4]),
                                mincost[i][i+3] + row[i] * column[i+3] * column[i + 4]);
  }
  

  
  
  printf("Matrix-chain Multiplication\n");
  for(length = 1; length < N; length++){
    for(left = 0; left < N - length; left++){
      printf("From %d to %d = %d\n",left,left+length, mincost[left][left+length]);
    }
  }
  printf("\nMinimum cost = %d\n", mincost[0][N-1]);
}

int min(int a, int b){
  if(a > b){
    return b;
  }else{
    return a;
  }
}
