// Programming in C Book - Fourth Edition
// Author: Stephen G. Kochan
// Date: 03-12-2024

#include <stdio.h>

int main(void) {

    // Declare integer variables
    int value1, value2, sum;

    // Assign values to variables
    value1 = 50;
    value2 = 25;
    sum = value1 + value2;

    // Display the result
    printf("The sum of %i and %i is %i\n", value1, value2, sum);

    return 0;
}

// gcc variables.c -o sum2
// ./sum2

// Output:
// The sum of 50 and 25 is 75