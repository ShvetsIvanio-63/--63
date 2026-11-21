#include <stdio.h>

int main() {
    int n;
    double x = 1.0 / 3, s = 0;
    long long op = 0;

    scanf("%d", &n);

    double r = (x - 1) / (x + 1);
    double r2 = r * r;
    double p = r;

    for (int i = 1; i <= n; i++) {
        s += p / (2 * i - 1);
        p *= r2;
        op += 5;
    }
    s *= 2;

    printf("%.7f\n", s);
    printf("op %lld\n", op);
    return 0;
}