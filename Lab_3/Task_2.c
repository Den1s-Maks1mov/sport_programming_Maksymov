// Напишіть програму, яка зчитує радіус кола та обчислює його площу. Формула: S=π∗r^2.(0.2 бала)
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main() {
    system("chcp 65001");
    double radius;
    printf("Введіть радіус кола: ");
    scanf("%lf", &radius);
    printf("Площа кола з радіусом %.2f дорівнює: %.2f\n", radius, M_PI * radius * radius);
    return 0;
}