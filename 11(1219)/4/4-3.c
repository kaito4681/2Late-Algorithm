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

    return 0;
}

int fibonacci(int n, int *f) {
    if (n == 0) {
        // f[0] = 0;
        return 0;
    } else if (n == 1) {
        // f[1] = 1;
        return 1;
    } else if (f[n] != -1) {
        printf("Fibonacci(%d) already calculated = %d\n", n, f[n]);
    } else {
        // printf("Call: Fibonacci(%d)\n", n);
        if (f[n - 1] == -1 && f[n - 2] == -1) {
			printf("a\n");
            printf("Call: Fibonacci(%d)\n", n - 1);
            f[n - 1] = fibonacci(n - 1, f);
            printf("aFibonacci(%d) = %d\n", n - 1, f[n - 1]);
            printf("Call: Fibonacci(%d)\n", n - 2);
            f[n - 2] = fibonacci(n - 2, f);
            printf("bFibonacci(%d) = %d\n", n - 2, f[n - 2]);

        } else if (f[n - 1] == -1) {
			printf("b\n");
            printf("Call: Fibonacci(%d)\n", n - 1);
            f[n - 1] = fibonacci(n - 1, f);
            printf("cFibonacci(%d) = %d\n", n - 1, f[n - 1]);
        } else if (f[n - 2] == -1) {
			printf("c\n");
            printf("Call: Fibonacci(%d)\n", n - 2);
            f[n - 2] = fibonacci(n - 2, f);
            printf("dFibonacci(%d) = %d\n", n - 2, f[n - 2]);
        }else{
			printf("d\n");
		}
		
        f[n] = f[n - 1] + f[n - 2];
        printf("     Fibonacci(%d) = %d\n", n, f[n]);
    }
    return f[n];
}
