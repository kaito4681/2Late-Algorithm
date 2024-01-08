#include <stdio.h>
#include <stdlib.h>

void recursive(int level, int n, int *binary);

int main(int argc, char **argv) {
    int n;
    int *binary;

    if (argc == 1) {
        fprintf(stderr, "\nUsage : %s input integer.\n", argv[0]);
        exit(1);
    }

    n = atoi(argv[1]);
    binary = malloc(sizeof(int) * n);
    recursive(0, n, binary);

    free(binary);  // メモリの解放

    return 0;
}

void recursive(int level, int n, int *binary) {
    int i;
    if (level == n) {
        // ビット列が完成したら表示
        for (i = 0; i < n; i++) {
            if (binary[i] == 0) {
                printf("0");
            } else {
                printf("1");
            }
        }
        printf("\n");
        return;
    }

    // ビットを 0 に設定して再帰呼び出し
    binary[level] = 0;
    recursive(level + 1, n, binary);

    // ビットを 1 に設定して再帰呼び出し
    binary[level] = 1;
    recursive(level + 1, n, binary);
}