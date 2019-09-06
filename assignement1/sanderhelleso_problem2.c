#include <stdio.h>

void printPadding(int *padding);
void printNumRow(int amount);
int binomialCoefficient(int outcomes, int possibilities); 

int main() {
    const int ROWS = 5;
    int padding = ROWS;

    int i;
    for (i = 1; i <= ROWS; i++) {
        printPadding(&padding);
        printNumRow(i);
    }

    return 0;
}

// http://mathworld.wolfram.com/BinomialCoefficient.html
int binomialCoefficient(int outcomes, int possibilities) { 
    int result = 1; 
    int i = 0;

    if (possibilities > outcomes - possibilities) {
        possibilities =  outcomes - possibilities; 
    }

    while (i < possibilities) {
        result *= (outcomes - i); 
        result /= (i + 1); 
        i++;
    }
      
    return result; 
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
        printf("%d ", binomialCoefficient(currentNum, i)); 
    }

    printf("\n");
}