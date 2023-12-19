//
//2023.10.17 3 main
//
#define N 6
#include <stdio.h>
#include <stdlib.h>

int **malloc_pascal();
void calc_pascal(int **traiangle);
void print_pascal(int **traiangle);
void free_pascal(int **traiangle);



int main(){
	int **triangle;

	triangle = malloc_pascal();
	calc_pascal(triangle);
	print_pascal(triangle);
	free_pascal(triangle);

	return 0;
}

int **malloc_pascal(){
	int **pascal;
	int i;

	if((pascal = (int **)malloc(sizeof(int *) * N))== NULL){
		fprintf(stderr, "Error: failure in malloc()\n");
		exit(1);
	}
	for(i = 0; i < N; i++){
		if((pascal[i] = (int *)malloc(sizeof(int) * (i + 1)))== NULL){
			fprintf(stderr, "Error: failure in malloc()\n");
			exit(1);
		}
	}

	return pascal;	
}

void calc_pascal(int **triangle){
	int i,j;

	for(i = 0;i < N;i++){
		triangle[i][0] = triangle[i][i] = 1;
	}

	for(i = 0;i < N;i++){
		for(j = 1;j < i;j++){
			triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
		}
	}
}

void print_pascal(int **triangle){
	int i,j;

	for(i = 0;i < N;i++){
		for(j = 0;j <= i;j++){
			printf("t[%d][%d]=%-2d     ",i,j,triangle[i][j]);
		}
		printf("\n");
	}
}

void free_pascal(int **triangle){
	int i;

	for(i = 0; i < N; i++){
		free(triangle[i]);
	}
	free(triangle);
}
