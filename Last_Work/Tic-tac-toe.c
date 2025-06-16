#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 9

// Вивід поля
void printBoard(char board[SIZE]) {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("    1 | 2 | 3\n");
    printf("    %c | %c | %c\n", board[0], board[1], board[2]);
    printf("   ---+---+---\n");
    printf("    4 | 5 | 6\n");
    printf("    %c | %c | %c\n", board[3], board[4], board[5]);
    printf("   ---+---+---\n");
    printf("    7 | 8 | 9\n");
    printf("    %c | %c | %c\n\n", board[6], board[7], board[8]);
}

// Перевірка перемоги
int checkWin(char board[SIZE], char symbol, int winLines[8][3]) {
    for (int i = 0; i < 8; i++)
        // Перевірка, чи всі три клітинки в лінії містять символ поточного гравця
        if (board[winLines[i][0]] == symbol &&
            board[winLines[i][1]] == symbol &&
            board[winLines[i][2]] == symbol)
            return 1;
    return 0;
}

// Застосування зникнення
void checkDisappearingMode(char board[SIZE], int moveHistory[], int moveCount) {
    // Режим зникнення починається з 7-го ходу
    if (moveCount > 6) {
        // Отримання індексу найстарішого ходу, який потрібно очистити
        int oldPosToClear = moveHistory[moveCount - 7];
        // Очищення клітинки на дошці
        board[oldPosToClear] = ' ';
    }
}

int main() {
    system("chcp 65001");
    srand(time(0));

    // Оголошення змінних
    char board[SIZE];
    char playerSymbol, computerSymbol;
    int moveHistory[SIZE * 3];
    int moveCount = 0;

    // Оголошення масиву з виграшними лініями
    int winLines[8][3] = {
        {0,1,2},
        {3,4,5},
        {6,7,8},
        {0,3,6},
        {1,4,7},
        {2,5,8},
        {0,4,8},
        {2,4,6}
    };

    // Вивід правил гри
    printf("\n\n-----------========= ПРАВИЛА ГРИ =========-----------\n");
    printf("\t- обрати X або O\n");
    printf("\t- ввести номер клітинки (1-9)\n");
    printf("\t- кожен 7-й хід найстаріша клітинка зникає\n\n");
    printf("Оберіть ваш символ (X або O): ");
    scanf(" %c", &playerSymbol);

    // Перевірка, чи коректно обрано символ гравця
    while (playerSymbol != 'X' && playerSymbol != 'O') {
        printf("Правильно оберіть ваш символ (X або O): ");
        scanf(" %c", &playerSymbol);
    }

    // Призначення символу комп'ютера на основі вибору гравця
    computerSymbol = (playerSymbol == 'X') ? 'O' : 'X';

    // Ініціалізація поля пробілами
    for (int i = 0; i < SIZE; i++) {
        board[i] = ' ';
    }

    // Перший вивід ігрового поля
    printBoard(board);

    // Тіло гри у циклі
    while (1) {
        // Хід гравця
        int playerPos;
        do {
            printf("Введіть номер клітинки (1-9): ");
            // Введення позиції гравця
            scanf("%d", &playerPos);
            // Перетворення введеної позиції на індекс масиву (0-8)
            playerPos--;

            // Перевірка валідності та доступності обраної клітинки
            if (playerPos < 0 || playerPos >= SIZE || board[playerPos] != ' ') {
                printf("Невірна позиція або клітинка зайнята. Спробуйте ще.\n");
            }
        } while (playerPos < 0 || playerPos >= SIZE || board[playerPos] != ' ');

        // Розміщення символу гравця на дошці
        board[playerPos] = playerSymbol;
        // Додавання запису ходу в історію та збільшення лічильника ходів
        moveHistory[moveCount++] = playerPos;

        // Перевірка перемоги гравця після його ходу
        if (checkWin(board, playerSymbol, winLines)) {
            printBoard(board); // Вивід фінального стану дошки
            printf("Ви перемогли)\n");
            break; // Завершення гри
        }

        // Застосування режиму зникнення після ходу гравця
        checkDisappearingMode(board, moveHistory, moveCount);
        // Оновлений вивід поля
        printBoard(board);

        // Хід комп'ютера
        int computerPos = -1;

        // Перевірка, чи може комп'ютер виграти на поточному ході
        for (int i = 0; i < SIZE; i++) {
            if (board[i] == ' ') {
                board[i] = computerSymbol;
                if (checkWin(board, computerSymbol, winLines)) {
                    computerPos = i; // Комп'ютер знахобить виграшний хід
                    break;
                }
                board[i] = ' '; // Відновлення стану дошки
            }
        }

        // Перевірка, якщо комп'ютер не може виграти, чи потрібно заблокувати гравця
        if (computerPos == -1) {
            for (int i = 0; i < SIZE; i++) {
                if (board[i] == ' ') {
                    board[i] = playerSymbol;
                    if (checkWin(board, playerSymbol, winLines)) {
                        board[i] = computerSymbol; // Комп'ютер блокує гравця
                        computerPos = i;
                        break;
                    }
                    board[i] = ' ';
                }
            }
        }

        // Якщо комп'ютер не може ні виграти, ні заблокувати, робиться випадковий хід
        if (computerPos == -1) {
            do {
                computerPos = rand() % SIZE; 
            } while (board[computerPos] != ' ');
            board[computerPos] = computerSymbol;
        }
        
        // Додавання запису ходу комп'ютера в історію та збільшення лічильника ходів
        moveHistory[moveCount++] = computerPos;

        // Перевірка перемоги комп'ютера після його ходу
        if (checkWin(board, computerSymbol, winLines)) {
            printBoard(board); // Вивід фінального стану дошки
            printf("Комп'ютер переміг(\n");
            break;
        }

        // Застосування режиму зникнення після ходу комп'ютера
        checkDisappearingMode(board, moveHistory, moveCount);
        // Оновлений вивід поля
        printBoard(board);
    }
    printf("Ви набрали балів: %d\n", moveCount);
    return 0;
}