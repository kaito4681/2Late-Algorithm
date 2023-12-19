//
// 2023 12.12 2 main
//
#include <stdio.h>
#include <stdlib.h>
#define N 4

struct LUGGAGE {
    int original_index, v, w;
    double vpw;
};

int main(int argc, char **argv) {
    double C;
    int w[N] = {2, 1, 4, 5};
    int v[N] = {2000, 3000, 3000, 4000};
    void greedy(double C, int *w, int *v);
    if (argc == 2) {
        C = atof(argv[1]);
        if (C > 0.0) {
            greedy(C, w, v);
        }
    } else
        printf("%s real number =>0\n", argv[0]);

    return 0;
}

void swap_luggages(struct LUGGAGE *a, struct LUGGAGE *b) {
    struct LUGGAGE temp;

    temp.original_index = a->original_index;
    temp.v = a->v;
    temp.w = a->w;
    temp.vpw = a->vpw;

    a->original_index = b->original_index;
    a->v = b->v;
    a->w = b->w;
    a->vpw = b->vpw;

    b->original_index = temp.original_index;
    b->v = temp.v;
    b->w = temp.w;
    b->vpw = temp.vpw;
}

void selection_sort(struct LUGGAGE *luggage) {
    int i, j, max_index;
    struct LUGGAGE temp;

    for (i = 0; i < N - 1; i++) {
        max_index = i;
        for (j = i + 1; j < N; j++) {
            if (luggage[j].vpw > luggage[max_index].vpw) {
                max_index = j;
            }
        }

        swap_luggages(&luggage[i], &luggage[max_index]);
    }
}


void greedy(double C, int *w, int *v) {
    struct LUGGAGE luggage[N];
    int i;
    double x[N];
    double total = 0;

    for (i = 0; i < N; i++) {
        luggage[i].v = v[i];
        luggage[i].w = w[i];
        luggage[i].vpw = (double)luggage[i].v / luggage[i].w;
        luggage[i].original_index = i;

        printf("w[%d]=%d  v[%d]=%d  v[%d]/w[%d]=%f\n", i, luggage[i].w, i,
               luggage[i].v, i, i, luggage[i].vpw);
    }

    selection_sort(luggage);
    printf("\n");
    for (i = 0; i < N; i++) {
        printf("v[%d]/w[%d]=%f\n", luggage[i].original_index,
               luggage[i].original_index, luggage[i].vpw);
    }
    printf("\n");

    for(i=0;i<N;i++){
        if(C>luggage[i].w){
            x[luggage[i].original_index] = 1;
            total += luggage[i].v;
            C -= luggage[i].w;
        }else{
            x[luggage[i].original_index] = C/luggage[i].w;
            total += x[luggage[i].original_index]*luggage[i].v;
            break;
        }
    }

    printf("total of value = %f\n",total);
    for(i = 0;i <N; i++){
        printf("x[%d]=%f   w[%d]*x[%d]=%f   v[%d]*x[%d]=%f\n",i,x[i],i,i,w[i]*x[i],i,i,v[i]*x[i]);
    }
    printf("\n");


}
