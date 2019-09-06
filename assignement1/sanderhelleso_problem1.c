#include <stdio.h>

void printPadding(int *padding);
void printNumRow(int amount);

int main() {
    const int ROWS = 4;
    int padding = ROWS;

    int i;
    for (i = 1; i <= ROWS; i++) {
        printPadding(&padding);
        printNumRow(i);
    }

    return 0;
}

void printPadding(int *padding) {
    int i;
    for (i = 1; i < *padding; i++) {
        printf(" ");
    }

    (*padding)--;
}

void printNumRow(int currentNum) {
    int i;
    for (i = 0; i < currentNum; i++) {
        printf("%d ", currentNum);
    }

    printf("\n");
}