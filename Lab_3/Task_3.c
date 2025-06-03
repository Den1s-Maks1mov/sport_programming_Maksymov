// Користувач вводить кількість секунд. Виведіть еквівалент у годинах, хвилинах і секундах.(0.2 бала)
#include <stdio.h>

int main() {
    system("chcp 65001");
    int totalSeconds;
    printf("Введіть кількість секунд: ");
    scanf("%d", &totalSeconds);

    int hours = totalSeconds / 3600;
    int remainingSeconds = totalSeconds % 3600;
    int minutes = remainingSeconds / 60;
    int seconds = remainingSeconds % 60;

    printf("\n%d секунд це:\n", totalSeconds);
    printf("%d годин, %d хвилин, %d секунд\n", hours, minutes, seconds);

    return 0;
}