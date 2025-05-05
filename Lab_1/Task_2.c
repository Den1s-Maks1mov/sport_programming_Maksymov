// Оголосити константну змінну типу float та присвоїти їй значення 3.14. Вивести її значення на екран. (0.2 бала)
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    system("chcp 65001");
    const float PI = 3.14;
    printf("\nЗначення константи PI: %f\n", PI);
    return 0;
}