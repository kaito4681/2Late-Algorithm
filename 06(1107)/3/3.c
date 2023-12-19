//
// 2023.11.07 3 main
//
#include <stdio.h>
#include <stdlib.h>

struct element {
    int data;
    struct element *next;
};

struct element *new_element(int data);
struct element *make_list2(int init, int deff, int num);
struct element *merge_list(struct element *list1, struct element *list2);
void print_list(struct element *list);

int main() {
    struct element *list1, *list2, *list3, *list;

    list1 = make_list2(1, 2, 5);
    list2 = make_list2(2, 2, 5);
    list3 = make_list2(1, 1, 10);

    printf("list1: ");
    print_list(list1);

    printf("list2: ");
    print_list(list2);

    printf("list3: ");
    print_list(list3);

    list = merge_list(list1, list2);
    printf("list1 + list2:\n");
    print_list(list);

    list = merge_list(list, list3);
    printf("list1 + list2 + list3:\n");
    print_list(list);

    return 0;
}

struct element *merge_list(struct element *list1, struct element *list2) {
    struct element *list, *current1, *current2, *current;

    // 初期化
    current1 = list1;
    current2 = list2;

    if (list1 == NULL) {
        return list2;
    } else if (list2 == NULL) {
        return list1;
    }

    if (list1->data > list2->data) {
        list = current = list2;
        current2 = current2->next;
    } else {
        list = current = list1;
        current1 = current1->next;
    }

    // マージ
    while (current1 != NULL && current2 != NULL) {
        if (current1->data > current2->data) {
            current->next = current2;
            current2 = current2->next;
        } else {
            current->next = current1;
            current1 = current1->next;
        }
        current = current->next;
    }

    // 残りのデータ
    if (current1 == NULL) {
        current->next = current2;
    } else {
        current->next = current1;
    }

    return list;
}

struct element *make_list2(int init, int diff, int num) {
    int i, data;
    struct element *list, *p;

    if (num < 1) {
        return NULL;
    }
    data = init;
    list = new_element(data);
    p = list;
    for (i = 1; i < num; i++) {
        data = data + diff;
        p->next = new_element(data);
        p = p->next;
    }
    return list;
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

void print_list(struct element *list) {
    while (list != NULL) {
        printf("%2d ", list->data);
        list = list->next;
    }
    printf("\n");
}