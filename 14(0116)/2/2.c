//
// 2024.01.16 2 main
//
#include <stdio.h>
#include <stdlib.h>

int euclid_recursion(int a, int b);

int main(int argc, char *argv[]) {
    int a, b, tmp;

    if (argc != 3) {
        printf("Input 2 intergers\n");
        exit(1);
    }

    a = atoi(argv[1]);
    b = atoi(argv[2]);

	if(b > a){
		tmp = b;
		b = a;
		a = tmp;
	}

    printf("gcd(%d,%d)=%d\n", a, b, euclid_recursion(a, b));

    return 0;
}

int euclid_recursion(int a, int b) {
    if(b == 0){
        return a;
    }else {
		return euclid_recursion(b, a % b);
	}
}

