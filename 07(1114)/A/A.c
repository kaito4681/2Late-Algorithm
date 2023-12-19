//
// 2023.11.14 A  main
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct element {
    int data;
    struct element *next;
};

struct element *new_element(int data);
void printlist(struct element *list);
struct element *insert(struct element *list, struct element *new);

int main() {
    int i;
    struct element *list;

    srandom(time(NULL));

    list = NULL;
    for (i = 0; i < 8; i++) {
        printlist(list);
        list = insert(list, new_element(random() % 100));
    }

    return 0;
}

struct element *new_element(int data) {
    struct element *new;
    new = malloc(sizeof(struct element));
    new->data = data;
    new->next = NULL;
    return new;
}

struct element *insert(struct element *list, struct element *new) {
    struct element *p, *pp;
    if (list == NULL) {
        list = new;
    } else {
        p = list;
        pp = NULL;
        while ((p != NULL) && (new->data < list->data)) {
            pp = p;
            p = p->next;
        }
        if(pp == NULL){
          new->next = list;
          list = new;
        }else{
          new->next = p;
          pp->next = new;
        }
    }
    return list;
}

void printlist(struct element *list) {
    if (list == NULL) {
        printf("\n");
        return;
    }

    printf("%d ", list->data);
    printlist(list->next);
}
