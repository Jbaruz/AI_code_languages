// If else example in C
// Author: JBA
// Date: 03-12-2024

#include <stdio.h>

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num % 2) {
        printf("The number is even\n");
    } else {
        printf("The number is odd\n");
    }
    return 0;

}