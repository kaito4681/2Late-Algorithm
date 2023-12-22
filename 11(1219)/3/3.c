//
// 2023.12.19 3 main
//
#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n);

int main(int argc, char *argv[]) {
    int n;

    if (argc != 2) {
        fprintf(stderr, "\nUsage : %s positive_integer \n\n", argv[0]);
        exit(1);
    }

    n = atoi(argv[1]);

    if (n >= 0) {
        printf("\nFibonacci(%d) = %d\n", n, fibonacci(n));
    }

    return -1;
}

int fibonacci(int n) {
    int result;

    printf("Call: Fibonacci(%d)\n", n);
    if (n == 0) {
		printf("Fibonacci(0) = 0\n");
        return 0;
    } else if (n == 1) {
		printf("Fibonacci(1) = 1\n");
        return 1;
    }
    result = fibonacci(n - 1) + fibonacci(n - 2);
    printf("Fibonacci(%d) = %d\n", n, result);
    return result;
}