//
//2023.10.03 3 main
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

int main(){
  int query, a[N],num;
  int dice();
  int search_array(int *a,int i);
  void make_array(int *a);
  void print_array(int *a);
  
  make_array(a);
  print_array(a);
  query = dice();
  num = search_array(a, query);
  
  printf("最初の%dの逐次探索に用いたifの回数は%dです.\n",query,num);
  
  return 0;
}


int dice(){
  //random 0-5
  return random() % 6;
}  
void make_array(int *a){
  int i ;
  
  srandom(time(NULL));
  
  for(i = 0;i < N;i++){
    a[i] = dice();
  }
}

void print_array(int *a){
  int i ;
  for(i = 0;i < N;i++){
    printf("a[%d] = %d\n",i , a[i]);
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