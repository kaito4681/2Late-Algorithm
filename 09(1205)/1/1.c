//
// 2023.12.05 1 main
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define MAX 100

struct element {
    int data;
    struct element *next;
};

struct element *make_list(int n);
void categorize(int key, struct element *list, struct element **small,
                struct element **big);
void print_data(struct element *list);

int main() {
    struct element *list, *small = NULL, *big = NULL;

    srandom(time(NULL));

    list = make_list(N);
    printf("Data\t");
    print_data(list);
    categorize(list->data, list->next, &small, &big);
    list->next = NULL;
    printf("The first data = %d\n",list->data);
    printf("%2d>=:\t", list->data);
    print_data(small);
    printf("%2d< :\t", list->data);
    print_data(big);
    return 0;
}

void categorize(int key, struct element *list, struct element **small,
                struct element **big) {
    struct element *small_tail = NULL;
    struct element *big_tail = NULL;
    struct element *current = list;
    struct element *new_element(int i);

    while (current != NULL) {
        if (current->data <= key) {
            if (small_tail == NULL) {
                *small = new_element(current->data);
                small_tail = *small;
            } else {
                small_tail->next = new_element(current->data);
                small_tail = small_tail->next;
            }
        } else {
            if (big_tail == NULL) {
                *big = new_element(current->data);
                big_tail = *big;
            } else {
                big_tail->next = new_element(current->data);
                big_tail = big_tail->next;
            }
        }
        current = current->next;
    }
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

struct element *make_list(int n) {
    int i;
    struct element *list, *current;

    current = list = new_element(random() % MAX);
    for (i = 1; i < n; i++) {
        current->next = new_element(random() % MAX);
        current = current->next;
    }
    return list;
}

void print_data(struct element *list) {
    while (list != NULL) {
        printf("%2d ", list->data);
        list = list->next;
    }
    printf("\n");
}