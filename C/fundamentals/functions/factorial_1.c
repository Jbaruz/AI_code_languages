// Factorial in C
// Author: JBA
// Date: 03-12-2024

#include <stdio.h> 

int factorial(int n) { // function to calculate factorial
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n -1); // Recursive call
}
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%i", &num);
    printf("Factorial de %i is %i\n", num, factorial(num));
    return 0;
}
