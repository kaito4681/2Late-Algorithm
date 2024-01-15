//
// 2024.01.09 3 main
//
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char c;
    int frequence;
    struct node *next;
    struct node *right;
    struct node *left;
} NODE;

int main(int argc, char *argv[]) {
    int num;
    int *counter;
    int string_length(char *array);
    void print_frequency(char *, int *, int num);
    int unique(char *array, int *counter, int n);
    int *malloc_counter_array(int n);
    void printlist(NODE * list);
    NODE *sort_list(NODE * list);
    NODE *make_list(char *array, int *counter, int num);
    NODE *list = NULL;

    if (argc != 2) {
        fprintf(stderr, "\nUsage : %s character string \n\n", argv[0]);
        exit(1);
    }

    printf("%s\n", argv[1]);
    num = string_length(argv[1]);
    printf("length of string = %d\n", num);
    counter = malloc_counter_array(num);
    num = unique(argv[1], counter, num);
    print_frequency(argv[1], counter, num);
    list = make_list(argv[1], counter, num);
    list = sort_list(list);
    printlist(list);
    return 0;
}

NODE *make_list(char *array, int *counter, int num) {
    int *exist, i;
    NODE *root, *current;

    if (array == NULL) {
        return 0;
    } else {
        exist = malloc(sizeof(int) * 256);

        for (i = 0; i < 256; i++) {
            exist[i] = 0;
        }

        root = malloc(sizeof(NODE));
        root->c = array[0];
        root->frequence = counter[0];
        root->left = NULL;
        root->right = NULL;
        root->next = NULL;

        current = root;

        if ('A' <= current->c && current->c <= 'z') {
            printf("(%c,%d) ", (int)current->c, current->frequence);
        } else {
            printf("(%d,%d) ", (int)current->c, current->frequence);
        }

        for (i = 1; array[i] != '\0'; i++) {
            if (exist[(unsigned char)array[i]] == 0) {
                exist[(unsigned char)array[i]] = 1;
                current->next = malloc(sizeof(NODE));
                current = current->next;
                current->c = array[i];
                current->frequence = counter[i];
                current->left = NULL;
                current->right = NULL;
                current->next = NULL;

                if ('A' <= current->c && current->c <= 'z') {
                    printf("(%c,%d) ", (int)current->c, current->frequence);
                } else {
                    printf("(%d,%d) ", (int)current->c, current->frequence);
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
                if (current->frequence > index->frequence) {
                    temp_c = current->c;
                    current->c = index->c;
                    index->c = temp_c;

                    temp_freq = current->frequence;
                    current->frequence = index->frequence;
                    index->frequence = temp_freq;
                }
            }
        }
    }

    return list;
}

void printlist(NODE *list) {
    while (list != NULL) {
        if ('A' <= list->c && list->c <= 'z') {
            printf("(%c,%d) ", (int)list->c, list->frequence);
        } else {
            printf("(%d,%d) ", (int)list->c, list->frequence);
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
        fprintf(stderr, "\nError : Failure in malloc \n\n");
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
        original_array = malloc(sizeof(int) * (string_length(array) + 1));

        for (i = 0; i < 256; i++) {
            exist[i] = 0;
        }

        for (i = 0; array[i] != '\0'; i++) {
            original_array[i] = array[i];
        }

        for (i = 0; i < n; i++) {
            if (exist[(unsigned char)array[i]] == 0) {
                exist[(unsigned char)array[i]] = 1;
                array[unique_count] = array[i];
                unique_count++;
            }
        }

        // 出てくる回数を調べる
        for (i = 0; i < unique_count; i++) {
            for (j = 0; original_array[j] != '\0'; j++) {
                if (array[i] == original_array[j]) {
                    counter[i]++;
                }
            }
        }

        free(exist);

        return unique_count;
    }
}

void print_frequency(char *array, int *counter, int num) {
    int i;

    if (array == NULL) {
        printf("NULL\n");
    } else {
        for (i = 0; i < num; i++) {
            printf("%c ", array[i]);
        }
        printf("\n");
    }

    if (counter == NULL) {
        printf("NULL\n");
    } else {
        for (i = 0; i < num; i++) {
            printf("%d ", counter[i]);
        }
        printf("\n");
    }
}
