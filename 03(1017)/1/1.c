//
//2023.10.17 1main
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct record {
	int data;
	struct record *next;
} RECORD;

RECORD *make_list(int n);
int swap(RECORD *);

int main(int argc, char *argv[]) {
	int i, times, size, count;
	unsigned long total = 0;
	RECORD *head;

	if (argc != 3) {
		fprintf(stderr, "\nUsage: %s <size> <times> \n size times : integer values.\n\n", argv[0]);
		exit(1);
	}

	size = atoi(argv[1]);
	times = atoi(argv[2]);
	srandom(time(NULL));

	while (times--) {
		head = make_list(size);
		for (count = i = 1; i < size; i++) {
			count += swap(head);
		}
		total += count;
	}

	printf("total/times = %f\n", (double)total / atof(argv[2]));

	return 0;
}

RECORD *make_list(int n) {
	int i;
	RECORD *list, *current;
	RECORD *new_record(int);

	current = list = new_record(random());
	for (i = 1; i < n; i++) {
		current->next = new_record(random());
		current = current->next;
	}
	return list;
}

RECORD *new_record(int i) {
	RECORD *new;

	if ((new = (RECORD *)malloc(sizeof(RECORD))) == NULL) {
		fprintf(stderr, "Error: failure in malloc()\n");
		exit(1);
	}

	new->data = i;
	new->next = NULL;
	return new;
}

int swap(RECORD *a) {
	int swap_data(RECORD *);
	int count = 0;
	

	if (a == NULL || a->next == NULL) {
		return count;
	}

	count += swap_data(a);
	count += swap(a->next);
	return count;
}

int swap_data(RECORD *a){
	int tmp,count = 0;

	if (a->data > a->next->data) {
		tmp = a->data;
		a->data = a->next->data;
		a->next->data = tmp;
		count++;
	}
	return count;
}
