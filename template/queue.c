//
// 
//
#define N 4

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char buffer[N];
    int front;
    int rear;
    int num;
} QUEUE;

void initialize(QUEUE *);
void batch(QUEUE *);
void enqueue(QUEUE *, int);
void dequeue(QUEUE *);
void printqueue(QUEUE *);

int main(void) {
    QUEUE queue;

    printf("The size of queue is %d.\n", N);
    initialize(&queue);
    batch(&queue);

    return 0;
}

void batch(QUEUE *queue) {
 

    printqueue(queue);
    enqueue(queue, 1);

    printqueue(queue);
    dequeue(queue);
}



void initialize(QUEUE *queue) {
    queue->front = 0;
    queue->rear = 0;
    queue->num = 0;
}

void enqueue(QUEUE *queue, int n) {
    if (queue->num == N) {
        printf("buffer overflow\n");
    } else {
        queue->buffer[queue->rear] = n;
        queue->num += 1;
        queue->rear = (queue->rear + 1) % N;
    }

    return;
}

void dequeue(QUEUE *queue) {
    if (queue->num == 0) {
        printf("queue is empty\n");
    } else {
        queue->front += 1;
        queue->num -= 1;
        queue->front %= N;
    }

    return;
}

void printqueue(QUEUE *queue) {
    int i;
    printf("(front, rear, num)=(%d,%d,%d):    ", queue->front, queue->rear,
           queue->num);
    for (i = 0; i < queue->num; i++) {
        printf("%d", queue->buffer[(queue->front + i) % N]);
    }
    printf("\n");
}
