//
// 2023.10.24 3 main
//
#include <stdio.h>
#include <stdlib.h>

struct element {
    int data;
    struct element *previous;
    struct element *next;
};

void print_list(struct element *list);
void print_list_reverse(struct element *list);
void delete_element(struct element **list);

int main() {
    int i;
    struct element a, b, c;
    struct element *list, *tail;

    for (i = 0; i < 2; i++) {
        list = &a;
        tail = &c;

        a.data = 1;
        b.data = 2;
        c.data = 3;

        a.previous = NULL;
        a.next = &b;

        b.previous = &a;
        b.next = &c;

        c.previous = &b;
        c.next = NULL;

        printf("sequence: ");
        print_list(list);
        printf("reverse:  ");
        print_list_reverse(tail);

        if (i == 0) {
            delete_element(&list);
        } else {
            delete_element(&tail);
        }

        printf("sequence: ");
        print_list(list);
        printf("reverse:  ");
        print_list_reverse(tail);
    }

    return 0;
}

void print_list(struct element *list) {
    while (list != NULL) {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");
}

void print_list_reverse(struct element *list) {
    while (list != NULL) {
        printf("%d ", list->data);
        list = list->previous;
    }
    printf("\n");
}

void delete_element(struct element **list) {
    struct element *p;

	p = *list;

    if (p->previous == NULL) {
        p->next->previous = p->previous;
        (*list) = (*list)->next;
    } else {
        p->previous->next = p->next;
        (*list) = (*list)->previous;
    }
}