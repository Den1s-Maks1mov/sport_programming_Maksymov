// Напишіть програму, яка зчитує символ та виводить наступний символ у таблиці ASCII.(0.2 бала)
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    system("chcp 65001");
    char a;
    printf("\nВведіть символ: ");
    scanf("%c", &a);
    printf("\nНаступний символ із таблиці ASCII: %c\n", a+1);
    return 0;
}