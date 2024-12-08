// Efficient matrix multiplication in C
// Author: JBA
// Date: 06-12-2024

#include <stdio.h>
#include <stdlib.h>

/*
 * FUNCTION: multiplyMatrices
 * --------------------------
 * This function takes three pointers to two-dimensional arrays (a, b, and result) 
 * and an integer n that indicates the size of the square matrices.
 * It multiplies matrix 'a' by matrix 'b' (both of size n x n) and stores the result 
 * in the 'result' matrix.
 *
 * For any element (i, j) in the result:
 * 
 *   result[i][j] = sum over k (a[i][k] * b[k][j])
 *
 * This is the standard formula for matrix multiplication.
 * Understanding matrix multiplication is crucial in many AI-related tasks, 
 * such as neural network computations, image transformations, and various linear algebra operations.
 */
void multiplyMatrices(int **a, int **b, int **result, int n ) {
    // We iterate through each row i of 'a'
    for (int i = 0; i < n; ++i) {
        // For each row 'i' of 'a', we iterate through each column j of 'b'
        for (int j = 0; j < n; ++j) {
            // First, set the element (i, j) of the result to 0.
            // We'll accumulate the sum of products into this.
            result[i][j] = 0;

            // To compute result[i][j], we go along the i-th row of 'a' and the j-th column of 'b'
            // multiplying corresponding elements and summing them.
            for (int k = 0; k < n; ++k) {
                // Add the product of a[i][k] and b[k][j] to the current sum.
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int n = 3; // We are dealing with 3x3 matrices for simplicity.
               // In AI and machine learning, matrices can be much larger. 
               // But the principle remains the same.

    // We need to create dynamic 2D arrays for 'a', 'b', and 'result'.
    // Here, we first allocate memory for arrays of pointers.
    int **a = (int **)malloc(n * sizeof(int *));
    int **b = (int **)malloc(n * sizeof(int *));
    int **result = (int **)malloc(n * sizeof(int *));

    // For each of these pointers, we now allocate a contiguous block of 'n' integers.
    // After this, 'a[i]', 'b[i]', and 'result[i]' each point to a row of the respective matrices.
    for (int i = 0; i < n; ++i) {
        a[i] = (int *)malloc(n * sizeof(int));
        b[i] = (int *)malloc(n * sizeof(int));
        result[i] = (int *)malloc(n * sizeof(int));
    }

    // Initialize the matrices with some values.
    // 'a' will get values 1, 2, 3, ... in increasing order.
    // 'b' will get values that are double those of 'a'.
    // This sets up a scenario where we know what the result should look like.
    // In AI, initializing matrices might represent setting input data or weights for a small example.
    int counter = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = counter;      // Fill matrix a with counter (1, 2, 3, ...)
            b[i][j] = counter * 2;  // Fill matrix b with double those values
            counter++;
        } 
    }

    // Perform the multiplication.
    // After this call, 'result' will contain the product of 'a' and 'b'.
    multiplyMatrices(a, b, result, n);

    // Print out the resulting matrix.
    // This helps us verify that the multiplication worked as expected.
    // In AI, we might not print results this way, but rather use them as inputs to other computations.
    printf("Result Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Free all the allocated memory.
    // It's important to release resources after use, especially for large matrices common in AI tasks.
    for (int i = 0; i < n; i++) {
        free(a[i]);
        free(b[i]);
        free(result[i]);
    }
    free(a);
    free(b);
    free(result);

    // Returning 0 indicates that the program ended successfully.
    return 0;
}

// Dynamic memory allocation with malloc ensures felxibility for matrix size.
// Optimized nested loops avoid unnecessary overhead.