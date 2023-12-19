//
// 2023.10.17 4 main 
//
#define N 4

#include<stdio.h> 
#include<stdlib.h>

typedef struct{
	char buffer[N];
	int front;
	int rear;
	int num;
}QUEUE;

QUEUE enqueue(QUEUE,int);
QUEUE dequeue(QUEUE);
void batch(QUEUE);
void printqueue(QUEUE);

int main(void){
	QUEUE queue;
	
	queue.front = 0;
	queue.rear = 0;
	queue.num = 0;
	batch(queue);

	return 0;

	
}

void batch(QUEUE queue){
	printqueue(queue);
	queue = enqueue(queue,1);  printqueue(queue);
	queue = enqueue(queue,2);  printqueue(queue);
	queue = enqueue(queue,3);  printqueue(queue);
	queue = dequeue(queue);    printqueue(queue);
	queue = enqueue(queue,4);  printqueue(queue);
	queue = enqueue(queue,5);  printqueue(queue); 
	queue = dequeue(queue);    printqueue(queue);
}


QUEUE enqueue(QUEUE queue,int n){
	queue.buffer[queue.rear] = n;
	queue.num += 1;
	queue.rear = (queue.rear + 1)% N;

	if(queue.num > N){
		fprintf(stderr,"overflow\n");
		exit(1);
	}
	return queue;
}

QUEUE dequeue(QUEUE queue){
	if(queue.num == 0){
		fprintf(stderr,"underlow\n");
		exit(1);
	}else{
		queue.front += 1;
		queue.num -= 1;
		queue.front %= N;
	}
	
	return queue;
}

void printqueue(QUEUE queue){
	int i;
	for(i = 0;i< queue.num;i++){
		printf("%d",queue.buffer[(queue.front + i) % N]);
	}
	printf("\n");
}

