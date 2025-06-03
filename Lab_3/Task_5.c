// Користувач вводить малу літеру англійського алфавіту. Перетворіть її на велику.(0.2 бала)
#include <stdio.h>

int main() {
    system("chcp 65001");
    char lowerCase;
    printf("Введіть малу літеру англійського алфавіту: ");
    scanf("%c", &lowerCase);

    if (lowerCase >= 'a' && lowerCase <= 'z') {
        printf("Велика літера: %c\n", lowerCase - 32);
    } else {
        printf("Введена літера не є малою літерою англійського алфавіту.\n");
    }
    return 0;
}