//
//2023.10.03 4 main
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1000
#define Trials 100000

int main(){
  int i,total;
  int NumOfIf();

  srandom(time(NULL)); 
  for(total = 0 ,i = 0;i < Trials; i ++){
    total = total + NumOfIf();
  }
  printf("N= %d, %d回の試行の結果,平均探索回数派%.3fでした.\n",N,Trials,(double)total/Trials);
  return 0;
}


int NumOfIf(){
  int query, a[N],num;
  int dice();
  int search_array(int *a,int i);
  void make_array(int *a);
  
  make_array(a);
  query = dice();
  num = search_array(a, query);

  return num;
}



int dice(){
  //random 0-5
  return random() % 6;
}
void make_array(int *a){
  int i;
  
  for(i = 0;i < N;i++){
    a[i] = dice();
  }
}


int search_array(int *a,int query){
  int num = 0;
  int i;
 
  for(i = 0;i < N;i++){
    if(a[i] == query){
      num++;
      break;
    }else{
      num++;
    }
  }  
  return num;
}