// Написати програму, яка оголошує змінну типу char та виводить її ASCII-код. (0.2 бала)
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    system("chcp 65001");
    char a = 'A';
    printf("\nASCII значення змінної: %d\n", a);
    return 0;
}