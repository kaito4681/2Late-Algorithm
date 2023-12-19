//
// 2023.12.12 B  main
//
#include <stdio.h>
#include <stdlib.h>
#define N 5

int main(int argc, char **argv) {
    int x;
    int currency[N] = {100, 50, 10, 5, 1};
    void coins(int, int *);

    if (argc == 2) {
        x = atoi(argv[1]);
        if (x >= 0) {
            coins(x, currency);
        } else {
            printf("%s integer>=0\n", argv[0]);
        }
    }
    return 0;
}

void coins(int x, int *currency) {
    int i,j;
    int coin[N];
    for (i = 0; i < N; i++) {
        coin[i] = 0;
    }

    j = x;

	for(i = 0;i<N-1;i++){
		while(j>=currency[i]){
			j -= currency[i];
			coin[i]++;
		}
	}
    coin[N-1] = j;

    printf("%d  = 100*%d + 50*%d + 10*%d + 5*%d + 1*%d\n", x, coin[0],
           coin[1], coin[3], coin[3], coin[4]);
    printf("the total number of coins = %d\n",
           coin[0] + coin[1] + coin[2] + coin[3] + coin[4]);
}
