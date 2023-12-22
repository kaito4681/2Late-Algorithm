//
// 2023.12.19 4 main
//
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

    for (i = 0; i < 40; i++) {
        f[i] = -1;
    }

    if (n >= 0 && n <= 40) {
        printf("\nFibonacci(%d) = %d\n", n, fibonacci(n, f));
    }

    return -1;
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
        if (f[n - 1] == -1 && f[n - 2] == -1) {
            f[n - 1] = fibonacci(n - 1, f);
            if (n - 1 == 0) {
                printf("Call: Fibonacci(0)\n");
                printf("Fibonacci(0) = 0\n");
            } else if (n - 1 == 1) {
                printf("Call: Fibonacci(1)\n");
                printf("Fibonacci(1) = 1\n");
            }

            f[n - 2] = fibonacci(n - 2, f);
            if (n - 2 == 0) {
                printf("Call: Fibonacci(0)\n");
                printf("Fibonacci(0) = 0\n");
            } else if (n - 2 == 1) {
                printf("Call: Fibonacci(1)\n");
                printf("Fibonacci(1) = 1\n");
            }

        } else if (f[n - 1] == -1) {
            f[n - 1] = fibonacci(n - 1, f);
            if (n - 1 == 0) {
                printf("Call: Fibonacci(0)\n");
                printf("Fibonacci(0) = 0\n");
            } else if (n - 1 == 1) {
                printf("Call: Fibonacci(1)\n");
                printf("Fibonacci(1) = 1\n");
            }

        } else if (f[n - 2] == -1) {
            f[n - 2] = fibonacci(n - 2, f);
            if (n - 2 == 0) {
                printf("Call: Fibonacci(0)\n");
                printf("Fibonacci(0) = 0\n");
            } else if (n - 2 == 1) {
                printf("Call: Fibonacci(1)\n");
                printf("Fibonacci(1) = 1\n");
            }
        }

        f[n] = f[n - 1] + f[n - 2];
        printf("Fibonacci(%d) = %d\n", n, f[n]);
    }
    return f[n];
}

// int fibonacci(int n, int *f) {
//     if (n == 0) {
// 		printf("Call: Fibonacci(%d)\n", n);
//         return 0;
//     } else if (n == 1) {
// 		printf("Call: Fibonacci(%d)\n", n);
//         return 1;
//     } else if (f[n] != -1) {
//         printf("     Call: Fibonacci(%d)\n", n);
//     } else {
// 		printf("Call: Fibonacci(%d)\n", n);
//         if (f[n - 1] == -1 && f[n - 2] == -1) {
//             f[n - 1] = fibonacci(n - 1, f);
// 			f[n - 2] = fibonacci(n - 2, f);
//         } else if (f[n - 1] == -1 ) {
//             f[n - 1] = fibonacci(n - 1, f);
//         } else if (f[n - 2] == -1 ) {
//             f[n - 2] = fibonacci(n - 2, f);
//         }

// 		f[n] = f[n-1] + f[n-2];
// 		printf("\nFibonacci(%d) = %d\n", n, f[n]);

//     }
//     return f[n];
// }
