#include <stdio.h>
#define M 8
#define N 7

int a[M][N], cmp, mov;

void print() {
    int i, j;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) printf("%4d", a[i][j]);
        printf("\n");
    }
}

void sort() {
    int i, j, k, p, t;
    for (j = 0; j < N; j++)
        for (i = 1; i < M; i++) {
            t = a[i][j];
            p = i;
            while (p > 0 && (cmp++, a[p - 1][j] < t)) p--;
            for (k = i; k > p; k--) { a[k][j] = a[k - 1][j]; mov++; }
            a[p][j] = t;
        }
}

int main() {
    int i, j;
    printf("matrix 8x7:\n");
    for (i = 0; i < M; i++)
        for (j = 0; j < N; j++) scanf("%d", &a[i][j]);
    sort();
    printf("\nSorted:\n");
    print();
    printf("compares: %d, moves: %d", cmp, mov);
    return 0;
}
