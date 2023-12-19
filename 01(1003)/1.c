//
//2023.10.03 1  main
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

int dice();
void store_symbols(char *a);
void delete(char *a);

int main(){
  char  a[N];

  srandom(time(NULL));
  
  store_symbols(a);
  printf("%s\n",a);

  delete(a);
  printf("%s\n",a);

  return 0;
}


int dice(){
  //random 0-4
  return random() % 5;
}  

void store_symbols(char *a){
  int i;
  
  for(i = 0 ; i < N - 1 ; i++){
    a[i] = 'a' + dice();
  }
  a[i] = '\0';
}

void delete(char *a){
  int i,j = 0;
  char b[N];
  
  for(i = 0 ; i < N - 1 ; i++){
    if(a[i] != 'd'){
      b[j++] = a[i];
    }
  }
  b[j] = '\0';
  
  for(i = 0 ; i <= j ; i++){
    a[i] = b[i];
  }
}

    



