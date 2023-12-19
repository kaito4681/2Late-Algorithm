//
// 2023.10.24 D main
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

struct element {
    int data;
    struct element *next;
};

struct element *make_list(int);
void evenodd(struct element *list, struct element **even, struct element **odd);
void print_list(struct element *list);
struct element *new_element(int);

int main() {
    struct element *list, *even = NULL, *odd = NULL;

    srandom(time(NULL));
    list = make_list(N);
    printf("Print data:\t");
    print_list(list);
    evenodd(list, &even, &odd);
    list = NULL;
    printf("Print even:\t");
    print_list(even);
    printf("Print odd:\t");
    print_list(odd);

    return 0;
}

void evenodd(struct element *list, struct element **even,struct element **odd) {
    struct element *eventail, *oddtail;

    *even = *odd = eventail = oddtail = NULL;
    while (list != NULL) {
        if (list->data % 2 == 0) {
            if (eventail == NULL) {
                *even = new_element(list->data);
                eventail = *even;
            } else {
                eventail->next = new_element(list->data);
                eventail = eventail->next;
            }
        } else {
            if (oddtail == NULL) {
                *odd = new_element(list->data);
                oddtail = *odd;
            } else {
                oddtail->next = new_element(list->data);
                oddtail = oddtail->next;
            }
        }
        list = list->next;
    }
    if (eventail != NULL) {
    }

    if (oddtail != NULL) {
    }
}

struct element *make_list(int n) {
    int i;
    struct element *list, *current;

    current = list = new_element(random() % N);
    for (i = 1; i < n; i++) {
        current->next = new_element(random() % N);
        current = current->next;
    }
    return list;
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

void print_list(struct element *list) {
    while (list != NULL) {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");
}