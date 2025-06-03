// Напишіть програму, яка зчитує вартість товару та відсоток знижки, а потім обчислює кінцеву вартість. (0.2 бала)
#include <stdio.h>

int main() {
    system("chcp 65001");
    float itemCost;
    float discountPercentage;
    
    printf("Введіть вартість товару: ");
    scanf("%f", &itemCost);
    
    printf("Введіть відсоток знижки: ");
    scanf("%f", &discountPercentage);
    
    printf("Кінцева вартість товару: %.2f грн\n", itemCost * (1 - discountPercentage / 100));
    
    return 0;
}