//
// 2024.01.23 D main
//
#include <stdio.h>
#include <stdlib.h>
#define N 5

int tri(int n, int t[31]);

int main(int argc, char *argv[]) {
    int i, n, t[31];

    if (argc != 2) {
        printf("Input positive integer:\n");
        exit(1);
    }
    n = atoi(argv[1]);

    for (i = 0; i < 30; i++) {
        t[i] = -1;
    }
    if (n >= 0 && N <= 30) {
        printf("\nt(%d) = %d\n", n, tri(n, t));
    }
    return 0;
}

int tri(int n, int t[31]) {
    printf("Call: t(%d)\n", n);
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 0;
    } else if (n == 2) {
        return 1;
    } else if (t[n] != -1) {
        return t[n];
    } else {
        t[n] = tri(n - 1, t) + tri(n - 2, t) + tri(n - 3, t);
        printf("t(%d) = %d\n", n, t[n]);
        return t[n];
    }
}