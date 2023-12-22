//
// 2023.12.19 4 main
//
#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n, int f[41]);

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




// int fibonacci(int n, int *f) {
//     if (n == 0) {
//         return 0;
//     } else if (n == 1) {
//         return 1;
//     } else if (f[n] != -1) {
// 		printf("%d", n);
//         //
//     } else {
// 		printf("Call: Fibonacci(%d)\n",n);
//         if (f[n - 1] == -1) {
//             f[n - 1] = fibonacci(n - 1, f);
// 			if(n == 1 || n == 2){
// 				int fibonacci(int n, int *f) {
//     if (n == 0) {
//         return 0;
//     } else if (n == 1) {
//         return 1;
//     } else if (f[n] != -1) {
// 		printf("%d", n);
//         //
//     } else {
// 		printf("Call: Fibonacci(%d)\n",n);
//         if (f[n - 1] == -1) {
//             f[n - 1] = fibonacci(n - 1, f);
// 			if(n == 1 || n == 2){
// 				printf("Call: Fibonacci(%d)\n",n-1);
// 			}
//             printf("Fibonacci(%d) = %d\n", n - 1, f[n - 1]);
//         }

//         if (f[n - 2] == -1) {
//             f[n - 2] = fibonacci(n - 2, f);
// 			if(n == 2 || n == 3){
// 				printf("Call: Fibonacci(%d)\n",n-2);
// 			}
//             printf("Fibonacci(%d) = %d\n", n - 2, f[n - 2]);
//         }
//         f[n] = f[n - 1] + f[n - 2];
//         printf("Fibonacci(%d) = %d\n", n, f[n]);
//     }
//     return f[n];
// }
// 			}
//             printf("Fibonacci(%d) = %d\n", n - 1, f[n - 1]);
//         }

//         if (f[n - 2] == -1) {
//             f[n - 2] = fibonacci(n - 2, f);
// 			if(n == 2 || n == 3){
// 				printf("Call: Fibonacci(%d)\n",n-2);
// 			}
//             printf("Fibonacci(%d) = %d\n", n - 2, f[n - 2]);
//         }
//         f[n] = f[n - 1] + f[n - 2];
//         printf("Fibonacci(%d) = %d\n", n, f[n]);
//     }
//     return f[n];
// }
// int fibonacci(int n, int f[41]) {
//     if (n == 0) {
//         // printf("Call: Fibonacci(0)\n");
// 		// f[0] = 0;
//         return 0;
//     } else if (n == 1) {
//         // printf("Call: Fibonacci(1)\n");
// 		// f[1] = 1;
//         return 1;
//     } else if (f[n] != -1) {
//         printf("Call: Fibonacci(%d)\n", n);
//     } else {
//         printf("Call: Fibonacci(%d)\n", n);

//         f[n - 1] = fibonacci(n - 1, f);
//         f[n - 2] = fibonacci(n - 2, f);
//         f[n] = f[n - 1] + f[n - 2];
//     }

//     printf("Fibonacci(%d) = %d\n", n, f[n]);
//     return f[n];
// }

// int fibonacci(int n, int f[41]) {
//     if (n == 0) {
//         return 0;
//     } else if (n == 1) {
//         return 1;
//     } else if (f[n] != -1) {
//         printf("Call: Fibonacci(%d)\n", n);
//     } else {
//         printf("Call: Fibonacci(%d)\n", n);

//         if ((n == 2 || n == 1) && f[n - 1] == -1) {
//             printf("Call: Fibonacci(%d)\n", n - 1);
//             f[n - 1] = fibonacci(n - 1, f);
//             printf("Fibonacci(%d) = %d\n", n - 1, f[n - 1]);
//         } else {
//             f[n - 1] = fibonacci(n - 1, f);
//         }

//         if ((n == 3 || n == 2) && f[n - 2] == -1) {
//             printf("Call: Fibonacci(%d)\n", n - 2);
//             f[n - 2] = fibonacci(n - 2, f);
//             printf("Fibonacci(%d) = %d\n", n - 2, f[n - 2]);
//         } else {
//             f[n - 2] = fibonacci(n - 2, f);
//         }

//         f[n] = f[n - 1] + f[n - 2];
//     }

//     printf("Fibonacci(%d) = %d\n", n, f[n]);
//     return f[n];
// }