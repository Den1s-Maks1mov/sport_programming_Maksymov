// Напишіть програму, яка зчитує ціле число та перевіряє, чи є воно парним.(0.2 бала)
#include <stdio.h>

int main() {
    system("chcp 65001");
    int number;
    printf("Введіть ціле число: ");
    scanf("%d", &number);

    if (number % 2 == 0) {
        printf("%d - парне число.\n", number);
    } else {
        printf("%d - непарне число.\n", number);
    }
    return 0;
}