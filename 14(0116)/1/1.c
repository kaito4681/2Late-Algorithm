//
// 2024.01.16 1 main
//
#include <stdio.h>
#include <stdlib.h>

int euclid_recursion(int a, int b);

int main(int argc, char *argv[]) {
    int a, b;

    if (argc != 3) {
        printf("Input 2 intergers\n");
        exit(1);
    }

    a = atoi(argv[1]);
    b = atoi(argv[2]);

    printf("gcd(%d,%d)=%d\n", a, b, euclid_recursion(a, b));

    return 0;
}

int euclid_recursion(int a, int b) {
    int temp;

    while (a != 0 && b != 0) {
        if (a > b) {
            temp = a;
            a = b;
            b = temp % b;
        } else {
            temp = b;
            b = a;
            a = temp % a;
        }
    }

    if (a == 0) {
        return b;
    } else {
        return a;
    }
}
