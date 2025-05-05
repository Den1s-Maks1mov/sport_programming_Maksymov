// Користувач вводить ціле і дробове число. Виведіть їх суму. (0.2 бала)
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    system("chcp 65001");
    int a;
    float b;
    printf("Введіть ціле число, і потім через пробіл дробове:\n");
    scanf("%d", &a);
    scanf("%f", &b);
    printf("\nСума цих чисел: %f\n", a+b);
    return 0;
}