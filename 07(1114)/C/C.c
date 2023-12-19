//
// 2023.11.14 C.c main
//

#include <stdio.h>

int binary_search(int *array, int num, int data);

int main(){
  int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

  printf(" 1: %d\n",binary_search(array,10,1));
  printf(" 5: %d\n", binary_search(array,10,5));
  printf("10: %d\n",binary_search(array,10,10));
  printf(" 0: %d\n",binary_search(array,10,0));
  printf("11: %d\n",binary_search(array,10,11));
}


int binary_search(int *list, int num,int data) {
  int m = (num + 1) / 2;  

  if(list[0]<data || num == 0){
    return 0;
  }else  if(list[m-1] == data){
     return 1;
  }else{
    if(list[m] < data){
      return binary_search(list,m,data);
    }else{
      return binary_search(list+m,num-m,data);
    }
  }
}

  