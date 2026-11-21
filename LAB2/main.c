#include <stdio.h>

int main() {
    int n;
    double x = 1.0 / 3, s = 0;
    long long op = 0;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        int k = 2 * i - 1;
        double a = 1, b = 1;
        for (int j = 1; j <= k; j++) {
            a *= x - 1;
            b *= x + 1;
            op += 4;
        }
        s += a / (k * b);
        op += 5;
    }
    s *= 2;

    printf("%.7f\n", s);
    printf("op %lld\n", op);
    return 0;
}
