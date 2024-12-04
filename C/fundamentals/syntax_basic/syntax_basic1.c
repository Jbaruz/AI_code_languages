// Syntax basic 1
// Author: Juan
// Date: 02/12/2024

#include <stdio.h> 

int main() {
    int a, b, sum; // Declare integer variables
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b); // Take input for two integers
    sum = a + b; // Add two numbers
    printf("The Sum %d + %d is equal to %d\n", a, b, sum); // Print the sum
    return 0; // Return 0 to indicate successful termination
}