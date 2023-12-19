//
// 2023.10.17 2 main
//
#define N 5
#define M 6 
#include<stdio.h> 
#include<stdlib.h>

int **malloc2d(void);
void calc_product(int **a); 
void print_matrix(int **a);
void free2d(int **a);

int main(void){

	int **a;
	a = malloc2d();
	calc_product(a);
	print_matrix(a);
	free2d(a);

	return 0;
}

int **malloc2d(){
	int **matrix;
	int i;

	if((matrix = (int **)malloc(sizeof(int *) * N))== NULL){
		fprintf(stderr, "Error: failure in malloc()\n");
		exit(1);
	}
	for(i = 0; i < N; i++){
		if((matrix[i] = (int *)malloc(sizeof(int) * M))== NULL){
			fprintf(stderr, "Error: failure in malloc()\n");
			exit(1);
		}
	}

	return matrix;	
}

void calc_product(int **a){
	int i,j;

	for(i = 0;i < N;i++){
		for(j = 0;j < M;j++){
			a[i][j] = i * j;
		}
	}
}

void print_matrix(int **a){
	int i,j;

	for(i = 0;i < N;i++){
		for(j = 0;j < M;j++){
			printf("a[%d][%d]=%-2d     ",i,j,a[i][j]);
		}
		printf("\n");
	}
}

void free2d(int **a){
	int i;

	for(i = 0; i < N; i++){
		free(a[i]);
	}
	free(a);
}
