#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n, int *f);

int main(int argc, char *argv[]) {
    int n, i, f[41];

    if (argc != 2) {
        fprintf(stderr, "\nUsage : %s positive_integer \n\n", argv[0]);
        exit(1);
    }

    n = atoi(argv[1]);

    for (i = 0; i < 41; i++) {
        f[i] = -1;
    }

    if (n >= 0 && n <= 40) {
        printf("\nFibonacci(%d) = %d\n", n, fibonacci(n, f));
    }

    for (i = 0; i < n; i++) {
        printf("%d\n", f[i]);
    }

    return 0;
}

int fibonacci(int n, int *f) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else if (f[n] != -1) {
        printf("Call: Fibonacci(%d)\n", n);
    } else {
        printf("Call: Fibonacci(%d)\n", n);
        f[n - 1] = fibonacci(n - 1, f);
        printf("Fibonacci(%d) = %d\n", n - 1, f[n - 1]);

        f[n - 2] = fibonacci(n - 2, f);
        printf("Fibonacci(%d) = %d\n", n - 2, f[n - 2]);
		
        f[n] = f[n - 1] + f[n - 2];
        printf("Fibonacci(%d) = %d\n", n, f[n]);
    }
    return f[n];
}