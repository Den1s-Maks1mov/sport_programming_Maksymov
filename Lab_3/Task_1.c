// Користувач вводить довжину в метрах. Виведіть її в сантиметрах і міліметрах. (0.2 бала)
#include <stdio.h>

int main() {
    system("chcp 65001");
    double meters;
    printf("Введіть довжину в метрах: ");
    scanf("%lf", &meters);

    printf("%.2f метрів це:\n", meters);
    printf("\t%.2f см, ", meters * 100);
    printf("\t%.2f мм\n", meters * 1000);

    return 0;
}