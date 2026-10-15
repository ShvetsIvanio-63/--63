#include <stdio.h>

int main() {
    double x, y;

    printf("x: ");
    scanf("%lf", &x);

    if (x >= 0 && x <= 7) {
        y = -6 * x * x + 8;
        printf("y = %lf\n", y);
    }
    else {
        if (x <= -10 || x >= 11) {
            y = -(x * x * x) / 7.0 + 10;
            printf("y = %lf\n", y);
        }
        else {
            printf("Функція не визначена для заданого x.\n");
        }
    }
}