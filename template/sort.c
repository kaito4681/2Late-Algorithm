// 選択ソート
// 最小値を見つけて1番目にに詰めて、それ以外から次の最小値を見つけて2番目に詰める
// 
// list: ソート対象の配列
// n: 配列の長さ
// i: ループカウンタ
// j: ループカウンタ
// t: 値を一時的に保存するための変数
// min: 最小値
// minpos: 最小値のインデックス
void selection_sort(int *list, int n) {
    int i, j, t, min, minpos;
    for (i = 0; i < n; i++) {
        minpos = i;
        min = list[minpos];
        for (j = i + 1; j < n; j++) {
            if (min > list[j]) {
                minpos = j;
                min = list[minpos];
            }
        }
        t = list[i];
        list[i] = list[minpos];
        list[minpos] = t;
    }
}

// 挿入ソート
// すでにソートされれいる部分に追加して、ほかをずらす
// 
// list リスト
// nデータ数
void insertion_sort(int list[], int n) {
    int i, j, t;
    for (i = 0; i < n - 1; i++) {
        j = i;
        while (j >= 0 && list[j] > list[j + 1]) {
            t = list[j];
            list[j] = list[j + 1];
            list[j + 1] = t;
            j--;
        }
    }
}

#include<stdio.h>

/* 値を入れ替える関数 */
void swap (int *x, int *y) {
  int temp;    // 値を一時保存する変数

  temp = *x;
  *x = *y;
  *y = temp;
}

/* pushdouwn操作 */
void push_heap (int array[], int first, int last) {
  int parent = first;   // 親
  int child = 2*parent;   // 左の子
  while (child <= last) {
    if ((child < last) && (array[child] < array[child+1])) {
       child++;   // 右の子の方が大きいとき、右の子を比較対象に設定
    }
    if (array[child] <= array[parent]) { break; }   // ヒープ済み
    swap(&array[child], &array[parent]);
    parent = child;
    child = 2* parent;
  }
}

/* ヒープソート */
void heap_sort (int list[], int n) {
  int i;

  for (i = n/2; i >= 1; i--) {
    push_heap(list, i, n);   // 全体をヒープ化
  }
  for (i = n; i >= 2; i--) {
    swap(&list[1], &list[i]);   // 最大のものを最後に
    push_heap(list, 1, i-1);   // ヒープ再構築
  }
}

int main (void) {
  int array[11] = { 0, 2, 1, 8, 5, 4, 7, 9, 10, 6, 3 };
  int i;

  printf("Before sort: ");
  for (i = 1; i < 11; i++) { printf("%d ", array[i]); }
  printf("\n");

  heap_sort(array, 10);

  printf("After sort: ");
  for (i = 1; i < 11; i++) { printf("%d ", array[i]); }
  printf("\n");

  return 0;
}