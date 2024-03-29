//
// 2024.01.09 3 main
//
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char c;
    int frequency;
    struct node *next;
    struct node *right;
    struct node *left;
} NODE;

int string_length(char *array);
int *malloc_counter_array(int n);
int unique(char *array, int *counter, int n);
NODE *make_list(char *array, int *counter, int num);
NODE *sort_list(NODE *list);
void printlist(NODE *list);
void print_frequency(char *array, int *counter, int num);

int main(int argc, char *argv[]) {
    int num;
    int *counter;
    NODE *list = NULL;

    if (argc != 2) {
        fprintf(stderr, "\nUsage: %s character string\n\n", argv[0]);
        exit(1);
    }

    printf("%s\n", argv[1]);
    num = string_length(argv[1]);
    printf("Length of string = %d\n", num);
    counter = malloc_counter_array(num);
    num = unique(argv[1], counter, num);
    print_frequency(argv[1], counter, num);
    list = make_list(argv[1], counter, num);
    list = sort_list(list);
    printlist(list);

    // Free allocated memory
    free(counter);
    while (list != NULL) {
        NODE *temp = list;
        list = list->next;
        free(temp);
    }

    return 0;
}

NODE *make_list(char *array, int *counter, int num) {
    int *exist, i;
    NODE *root, *current;

    if (array == NULL) {
        return NULL;
    } else {
        exist = malloc(sizeof(int) * 256);

        for (i = 0; i < 256; i++) {
            exist[i] = 0;
        }

        root = malloc(sizeof(NODE));
        root->c = array[0];
        root->frequency = counter[0];
        root->left = NULL;
        root->right = NULL;
        root->next = NULL;

        current = root;

        for (i = 1; array[i] != '\0'; i++) {
            if (exist[(unsigned char)array[i]] == 0) {
                exist[(unsigned char)array[i]] = 1;
                current->next = malloc(sizeof(NODE));
                current = current->next;
                current->c = array[i];
                current->frequency = counter[i];
                current->left = NULL;
                current->right = NULL;
                current->next = NULL;

                if ('A' <= current->c && current->c <= 'z') {
                    printf("(%c,%d) ", current->c, current->frequency);
                } else {
                    printf("(%d,%d) ", current->c, current->frequency);
                }
            }
        }
        free(exist);
    }
    printf("\n");

    return root;
}

NODE *sort_list(NODE *list) {
    NODE *current, *index;
    char temp_c;
    int temp_freq;

    if (list == NULL) {
        return list;
    } else {
        for (current = list; current != NULL; current = current->next) {
            for (index = current->next; index != NULL; index = index->next) {
                if (current->frequency > index->frequency) {
                    temp_c = current->c;
                    current->c = index->c;
                    index->c = temp_c;

                    temp_freq = current->frequency;
                    current->frequency = index->frequency;
                    index->frequency = temp_freq;
                }
            }
        }
    }

    return list;
}

void printlist(NODE *list) {
    while (list != NULL) {
        if ('A' <= list->c && list->c <= 'z') {
            printf("(%c,%d) ", list->c, list->frequency);
        } else {
            printf("(%d,%d) ", list->c, list->frequency);
        }
        list = list->next;
    }
    printf("\n");
}

int string_length(char *array) {
    int i;

    for (i = 0; array[i] != '\0'; i++) {
    }

    return i;
}

int *malloc_counter_array(int n) {
    int *a, i;

    if ((a = malloc(sizeof(int) * n)) == NULL) {
        fprintf(stderr, "\nError: Failure in malloc\n\n");
        exit(1);
    }

    for (i = 0; i < n; i++) {
        a[i] = 0;
    }

    return a;
}

int unique(char *array, int *counter, int n) {
    int *exist, i, j, unique_count = 0;
    char *original_array;

    if (array == NULL) {
        return 0;
    } else {
        exist = malloc(sizeof(int) * 256);
        original_array = malloc(sizeof(char) * (string_length(array) + 1));

        for (i = 0; i < 256; i++) {
            exist[i] = 0;
        }

        for (i = 0; array[i] != '\0'; i++) {
            original_array[i] = array[i];
        }
        original_array[i] = '\0';

        for (i = 0; i < n; i++) {
            if (exist[(unsigned char)array[i]] == 0) {
                exist[(unsigned char)array[i]] = 1;
                array[unique_count] = array[i];
                unique_count++;
            }
        }
        // Count occurrences
        for (i = 0; i < unique_count; i++) {
            for (j = 0; original_array[j] != '\0'; j++) {
                if (array[i] == original_array[j]) {
                    counter[i]++;
                }
            }
        }

        free(exist);
        free(original_array);

        return unique_count;
    }
}

void print_frequency(char *array, int *counter, int num) {
    int i;
    if (array == NULL || counter == NULL) {
        printf("NULL\n");
        return;
    }

    for (i = 0; i < num; i++) {
        printf("%c ", array[i]);
    }
    printf("\n");

    for (i = 0; i < num; i++) {
        printf("%d ", counter[i]);
    }
    printf("\n");
}