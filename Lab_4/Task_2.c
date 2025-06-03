// Напишіть програму, яка зчитує рік народження та обчислює вік людини.(0.2 бала)
#include <stdio.h>

int main() {
    system("chcp 65001");
    int birthYear;
    int currentYear; 
    
    printf("Введіть ваш рік народження: ");
    scanf("%d", &birthYear);
    
    printf("Введіть поточний рік: ");
    scanf("%d", &currentYear); 
    
    printf("Ваш вік: %d років\n", currentYear - birthYear);
    
    return 0;
}