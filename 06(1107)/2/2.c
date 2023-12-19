//
// 2023.11.07 2 main
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

struct element *new_element(int data);
struct element *make_list(int num);
void split_list(struct element **list1, struct element **list2);
void print_list(struct element *list);

int main() {
    struct element *list1, *list2;

    srandom(time(NULL));

    list1 = make_list(N);
    list2 = NULL;
    printf("Print data: \t");
    print_list(list1);
    split_list(&list1, &list2);
    print_list(list1);
    print_list(list2);
    return 0;
}

void split_list(struct element **list1, struct element **list2) {
    struct element *current = *list1, *current1 = NULL, *current2 = NULL;
    int i;

    // 初期化
    if (*list1 == NULL || (*list1)->next == NULL) {
        *list2 = NULL;
    } else {
        current1 = *list1;
        *list2 = current2 = (*list1)->next;

        // list1をsplit
        //iはcurrentの位置
        for (i = 2, current = current->next; current->next != NULL;
             i++, current = current->next) {
            if (i % 2 == 0) {
                current1->next = current->next;
                current1 = current1->next;
            } else {
                current2->next = current->next;
                current2 = current2->next;
            }
        }

        // 最後にNULL
        if (i % 2 == 0) {
            current1->next = NULL;
        } else {
            current2->next = NULL;
        }
    }
}

struct element *new_element(int data) {
    struct element *p;
    if ((p = (struct element *)malloc(sizeof(struct element))) == NULL) {
        fprintf(stderr, "Error: failure in malloc()\n");
        exit(1);
    }
    p->data = data;
    p->next = NULL;
    return p;
}

struct element *make_list(int num) {
    int i;
    struct element *list, *p;

    if (num < 1) {
        return NULL;
    }

    list = new_element(random() % MAX);
    p = list;
    for (i = 1; i < N; i++) {
        p->next = new_element(random() % MAX);
        p = p->next;
    }
    return list;
}

void print_list(struct element *list) {
    while (list != NULL) {
        printf("%2d ", list->data);
        list = list->next;
    }
    printf("\n");
}