// Ти купуєш гру за 450 грн із знижкою 15%. Обчисли ціну зі знижкою і виведи її як ціле число. (0.2 бала)
#include <stdio.h>

int main() {
    system("chcp 65001");
    int originalPrice = 450;
    float discountPercentage = 15.0;
    
    float discountedPriceFloat = originalPrice * (1 - discountPercentage / 100);
    int discountedPriceInt = (int)discountedPriceFloat;
    
    printf("Ціна гри зі знижкою: %d грн\n", discountedPriceInt);
    
    return 0;
}