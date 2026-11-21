#include <stdio.h>

int main() {
    double x, y;

    printf("x: ");
    scanf("%lf", &x);

    if (x >= 0) {
        if (x <= 7) {
            y = -6 * x * x + 8;
            printf("y = %lf\n", y);
        } else {
            if (x >= 11) {
                y = -(x * x * x) / 7.0 + 10;
                printf("y = %lf\n", y);
            } else { // x між 7 та 11 — порожнеча
                printf("Function is not defined for the given x.\n");
            }
        }
    }
    else {
        if (x <= -10) {
            y = -(x * x * x) / 7.0 + 10;
            printf("y = %lf\n", y);
        } else {
            printf("Function is not defined for the given x.\n");
        }
    }
}