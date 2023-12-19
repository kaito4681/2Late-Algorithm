//
// 2023.10.24 1 main
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
void add_next_element(struct element **tail,struct element *c);

int main() {
	struct element a,b,c;
    struct element *list,*tail;

	list = &a;
	tail = &b;
	a.data = 1;
	b.data = 2;
	a.previous = NULL;
	a.next = &b;
	b.previous = &a;
	b.next = NULL;
	printf("sequence: ");
	print_list(list);
	printf("reverse:  ");
	print_list_reverse(tail);
	
	c.data = 3;
	printf("c.data = %d\n",c.data);
	add_next_element(&tail,&c);
	printf("sequence: ");
	print_list(list);
	printf("reverse:  ");
	print_list_reverse(tail);
	return 0;
}


void add_next_element(struct element **tail,struct element *c){
	struct element *new;

	if ((new = malloc(sizeof(struct element))) == NULL) {
        fprintf(stderr, "Error: failure in malloc()\n");
        exit(1);
	}
	
	new->data = c->data;
	new->next = NULL;
	new->previous = *tail;
	(*tail)->next = new;
	*tail = (*tail)->next; 
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