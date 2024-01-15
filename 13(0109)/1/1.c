//
// 2024.01.09 1 main
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

int *make_array(int n);
int unique(int *array, int n);
void print_array(int *array, int num);

int main() {
    int *array, num;

    srandom(time(NULL));
    array = make_array(N);
    print_array(array, N);
    num = unique(array, N);
    print_array(array, num);
    return 0;
}

int *make_array(int n) {
    int *array, i;

    array = malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        array[i] = random() % 10;
    }

    return array;
}

int unique(int *array, int n) {
    int *exist, i, unique_count = 0;//unique_count すでに出てきている数字の数

    if (array == NULL) {
        return 0;
    } else {
        exist = malloc(sizeof(int) * n);
        for (i = 0; i < n; i++) {
            exist[i] = 0;
        }

        for (i = 0; i < n; i++) {
            if (exist[array[i]] == 0) {
                exist[array[i]] = 1;
                array[unique_count] = array[i];
                unique_count++;
            }
        }
        free(exist);

        return unique_count;
    }
}

void print_array(int *array, int num) {
    int i;

    if (array == NULL) {
        printf("NULL\n");
    } else {
        for (i = 0; i < num; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
    }
}
