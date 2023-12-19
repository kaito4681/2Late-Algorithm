//
// 2023.11.14 D main
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM_OF_DATA 7
#define BASE 10

void init_array(int *array);
void print_array(int *array);
void open_address_hash(int *array, int data);

int main() {
    int array[BASE];
    int i, data;

    srandom(time(NULL));
    init_array(array);
    for (i = 0; i < NUM_OF_DATA; i++) {
        data = random() % 100;
        printf("data = %d\n", data);
        open_address_hash(array, data);
        print_array(array);
    }
}

void init_array(int *array) {
    int i;
    for (i = 0; i < BASE; i++) {
        array[i] = -1;
    }
}

void print_array(int *array) {
    int i;
    for (i = 0; i < BASE; i++) {
        if (array[i] != -1) {
            printf("  a[%d] = %3d", i, array[i]);
        }
    }
    printf("\n");
}
void open_address_hash(int *array, int data) {
    int i;
    if (array[data % 10] == -1) {
        array[data % 10] = data;
    } else {
        for (i = 1; (array[(data + i) % 10] != -1) && (i <= 9); i++) {
        }
        if (i != 10) { //空いているところがあるとき
            array[(data + i) % 10] = data;
        }
    }
}
