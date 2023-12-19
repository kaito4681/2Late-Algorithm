//
// 2023.10.31 2 main
//
#include <stdio.h>
#include <stdlib.h>

struct element {
    int data;
    struct element *next;
};

struct queue {
    int data;
    struct element *front;
    struct element *rear;
};

struct queue enqueue(struct queue, int);
struct queue dequeue(struct queue Q);
void print_list(struct element *list);
struct element *new_element(int i);

int main(void) {
    struct queue Q;
    Q.front = Q.rear = NULL;
    print_list(Q.front);

    Q = enqueue(Q, 1);
    print_list(Q.front);

	Q = dequeue(Q);
        print_list(Q.front);

    Q = enqueue(Q, 2);
    print_list(Q.front);

    Q = enqueue(Q, 3);
    print_list(Q.front);

    Q = enqueue(Q, 5);
    print_list(Q.front);

    Q = enqueue(Q, 8);
    print_list(Q.front);

    Q = enqueue(Q, 13);
    print_list(Q.front);

    Q = enqueue(Q, 21);
    print_list(Q.front);

    while (Q.front != NULL) {
        Q = dequeue(Q);
        print_list(Q.front);
    }

    Q = dequeue(Q);

    Q = enqueue(Q, 34);
    print_list(Q.front);

    return 0;
}

struct queue enqueue(struct queue Q, int datum) {
    if (Q.front == NULL) {
        Q.front = Q.rear = new_element(datum);
    } else {
        Q.rear->next = new_element(datum);
        Q.rear = Q.rear->next;
    }
    return Q;
}

struct queue dequeue(struct queue Q) {
    struct element *front;

    if (Q.front == NULL) {
        printf("Erorr: Queue is empty\n");
    } else {
        front = Q.front;
        Q.front = Q.front->next;
        free(front);
    }
    return Q;
}

void print_list(struct element *list) {
    if (list == NULL) {
        printf("\n");
        return;
    }

    printf("%d ", list->data);
    print_list(list->next);
}

struct element *new_element(int i) {
    struct element *new;

    if ((new = malloc(sizeof(struct element))) == NULL) {
        fprintf(stderr, "Error: failure in malloc()\n");
        exit(1);
    }

    new->data = i;
    new->next = NULL;
    return new;
}