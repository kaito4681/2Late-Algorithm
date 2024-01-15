//
// 2024.01.09 2 main
//
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int num;
    int *counter;
    int string_length(char *array);
    void print_frequency(char *, int *, int num);
    int unique(char *array, int *counter, int n);
    int *malloc_counter_array(int n);

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

    return 0;
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

	for(i = 0; i  < n; i++){
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

        for (i = 0; i < n; i++) {
            if (exist[array[i]] == 0) {
                exist[array[i]] = 1;
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
