//
//2023.10.10 5.c
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc,char **argv){
  int n,m;
  int i,j;
  int *result;
  int result_n;
  int sum = 0;
  
  //Usage
  if(argc != 3){
    fprintf(stderr,"\nUsage: %s n m \n\n",argv[0]);
    exit(1);
  }

    

  n = atoi(argv[1]);
  m = atoi(argv[2]);
  
  //malloc
  if((result = (int *)malloc(sizeof(int) * 5 * n)) == NULL){
    fprintf(stderr,"\nError : failure in malloc\n\n");
    exit(1);
  }
 	
  
  
  srandom(time(NULL));

  result += n;
 
  
  for(i = n ; i <= 6 * n ; i++){
    result[i] = 0;
  }
  
  for(i = 0;i < m ; i++){
    for(result_n = 0,j = 0 ; j< n ; j++){
      result_n += random() % 6 + 1;
    }
    result[result_n]++;
    sum += result_n;
  }

  for(i = n ; i <= 6*n ; i++){
    printf("%3d :%10d\n",i,result[i]);
  }
  
  printf("Average  = %d/%d = %f\n",sum,m,sum /(double) m);
  free(result - n);
  
  return 0;
}

      