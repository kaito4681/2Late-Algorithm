//
//2023.10.10 3.c
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv){
  int *x;
  int n = argc,i,j,k;
  
  if(argc < 4){  
    fprintf(stderr,"The cardinality of data set should be greater than 3\n");
    exit(1);
  }
  
  if((x = (int *)malloc(sizeof(int) * n)) == NULL){
    fprintf(stderr,"\nError : failure in malloc\n\n");
    exit(1);
  }

  printf("The cardinality of data set = %d\n",n-1);
  for(i = 1; i < n ; i++){
    x[i] = atoi(argv[i]);
    printf("%d ",x[i]);
  }
  printf("\n");

  for(i = 1; i < n - 1;i++){
    for(j = i + 1;j < n; j++){
      for(k = 1 ; k < n ; k++){
			if((x[i]+x[j] == x[k])
				printf("(%d, %d, %d)\n",x[i],x[j],x[k]);
	}
      }
    }
  }

  free(x);
  return 0;
}

      