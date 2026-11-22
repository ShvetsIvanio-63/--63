#include <stdio.h>
int main()
{
    double a[10][10];
    int n, i, j, l, r, m;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%lf", &a[i][j]);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%7.2f ", a[i][j]);
        printf("\n");
    }

    l = 0;
    r = n;
    while (l < r) {
        m = (l + r) / 2;
        if (a[m][m] < 0)
            l = m + 1;
        else
            r = m;
    }

    if (l < n && a[l][l] <= 5)
        printf("Found: a[%d][%d] = %.2f\n", l + 1, l + 1, a[l][l]);
    else
        printf("Not found\n");

    return 0;
}
