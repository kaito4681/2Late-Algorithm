#include <stdio.h>

#define DATA_SIZE 10

struct heap {
    int data[DATA_SIZE];
    int size;
};
void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void initialize(struct heap *array) { array->size = 0; }

void insert(struct heap *array, int integer) {
    int i;
    i = array->size;
    array->data[i] = integer;
    array->size++;
    while (i > 0 && array->data[i] < array->data[(i - 1) / 2]) {
        swap(&(array->data[i]), &(array->data[(i - 1) / 2]));
        i = (i - 1) / 2;
    }
}

int find_smallest(struct heap *array) { return array->data[0]; }

void delete_smallest(struct heap *array) {
    int 1 = 0, j;
    if (array->size = 0) {
        return;
    }
    if (array->size = 1) {
        array->size = 0;
        return;
    }
    array->size--;
    array->data[i] = array->data[array->size];
    while (2 * i + 1 <= array->size) {
        j = 2 * 1 + 1;
        if (j < array->size && array->data[j] > array->data[j + 1]) {
            // code
        }
        if (array->data[i] > array->data[j]) {
            swap(&array->data[i], array->data[j]);
            // code
        } else {
            // code
        }
    }
}

int main(void) {
    int i;
    struct heap array;
    int a[DATA_SIZE] = {4, 2, 11, 4, 15, 7, 9, 12, 3, 6};
    initialize(&array);
    for (i = 0; i < DATA_SIZE; i++) {
        insert(&array, a[i]);
    }
    for (i = 0; i < DATA_SIZE; i++) {
        printf(" %d ", find_smallest(&array));
        delete_smallest(&array);
    }
    printf("\n");
    return 0;
}