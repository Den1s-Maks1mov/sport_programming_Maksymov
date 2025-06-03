// Користувач вводить тризначне число. Обчисліть та виведіть суму його цифр.(0.2 бала)
#include <stdio.h>

int main() {
    system("chcp 65001");
    int number;
    int sumOfDigits;
    
    printf("Введіть тризначне число: ");
    scanf("%d", &number);
    
    if (number < 100 || number > 999) {
        printf("Будь ласка, введіть саме тризначне число.\n");
        return 1;
    }
    
    sumOfDigits = (number / 100) + ((number / 10) % 10) + (number % 10);
    
    printf("Сума цифр числа %d: %d\n", number, sumOfDigits);
    
    return 0;
}