//
// 2023.12.12 A  main
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 8
#define MAX 100

struct element {
    int data;
    struct element *next;
};

struct element *new_element(int i);
struct element *make_list(int n);
void split_list(struct element **list1, struct element **list2);
struct element *merge_list(struct element *list1, struct element *list2);
void print_list(struct element *list);
void merge_sort_list(struct element **list);

int main() {
    struct element *list;

    srandom(time(NULL));

    list = make_list(N);
    print_list(list);
    merge_sort_list(&list);
    print_list(list);
    return 0;
}

struct element *new_element(int data) {
    struct element *p;
    if ((p = (struct element *)malloc(sizeof(struct element))) == NULL) {
        fprintf(stderr, "Error: failure in malloc()\n");
    }
    p->data = data;
    p->next = NULL;
    return p;
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

void split_list(struct element **list1, struct element **list2) {
    struct element *t1, *t2, *e1, *e2, *list;

    t1 = t2 = e1 = e2 = NULL;

    list = *list1;

    while (list != NULL) {
        if (t1 == NULL) {
            t1 = e1 = list;
        } else {
            e1->next = list;
            e1 = e1->next;
        }
        list = list->next;

        if (list != NULL) {
            if (t2 == NULL) {
                t2 = e2 = list;
            } else {
                e2->next = list;
                e2 = e2->next;
            }
            list = list->next;
        }
    }
    if (e1 != NULL) {
        e1->next = NULL;
    }
    if (e2 != NULL) {
        e2->next = NULL;
    }

    *list1 = t1;
    *list2 = t2;
}

struct element *merge_list(struct element *list1, struct element *list2) {
    struct element *head, *tail;

    head = tail = NULL;

    while ((list1 != NULL) && (list2 != NULL)) {
        if (list1->data <= list2->data) {
            if (head == NULL) {
                head = tail = list1;
            } else {
                tail->next = list1;
                tail = tail->next;
            }
            list1 = list1->next;
        } else {
            if (head == NULL) {
                head = tail = list2;
            } else {
                tail->next = list2;
                tail = tail->next;
            }
            list2 = list2->next;
        }
    }
    if (list1 != NULL) {
        tail->next = list1;
    } else {
        if (list2 != NULL) {
            tail->next = list2;
        } else {
            tail->next = NULL;
        }
    }

    return head;
}

void print_list(struct element *list) {
    while (list != NULL) {
        printf("%2d ", list->data);
        list = list->next;
    }
    printf("\n");
}

void merge_sort_list(struct element **list) {
    struct element *list1, *list2;
	list1 = *list;
	list2 = NULL;

    split_list(&list1, &list2);
    if (list1->next != NULL) {
        merge_sort_list(&list1);
    }
    if (list2->next != NULL) {
        merge_sort_list(&list2);
    }
    *list = merge_list(list1, list2);
}
