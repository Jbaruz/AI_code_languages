// Sparse Matrix representation - C Programming
// Save memory when working with sparse datasets common in AI systems.
// Author: JBA
// Date: 08-12-2024

#include <stdio.h>
#include <stdlib.h>

// We define a structure to hold information about a single non-zero element in a sparse matrix.
// A sparse matrix is one in which most of the elements are zero, and only a few are non-zero.
// Instead of storing all elements (including zeros), we store only the non-zero elements and their positions.
//
// For AI learners: Sparse matrices are very common in machine learning and data science. 
// For example, representing text data in a "bag-of-words" model often leads to very large matrices with many zeros. 
// Handling these matrices as sparse can save a lot of memory and speed up operations.
typedef struct {
    int row;   // The row index of the non-zero element
    int col;   // The column index of the non-zero element
    int value; // The actual non-zero value at that position
} SparseElement;

// This structure represents the entire sparse matrix in a compressed form:
// - 'rows' and 'cols' give the dimension of the full matrix.
// - 'nonZeroCount' tells us how many non-zero elements there are.
// - 'elements' is an array holding each non-zero element as a SparseElement.
// For AI: think of this as a memory-efficient way to store only the data that matters.
typedef struct {
    int rows;          // Total number of rows in the matrix
    int cols;          // Total number of columns in the matrix
    int nonZeroCount;  // Number of non-zero elements
    SparseElement *elements; // Dynamic array of non-zero elements
} SparseMatrix;

// This function creates and returns a pointer to a SparseMatrix.
// It allocates memory for the structure and for the array of elements.
SparseMatrix *createSparseMatrix(int rows, int cols, int nonZeroCount) {
    // Allocate memory for the SparseMatrix structure
    SparseMatrix *sm = (SparseMatrix *)malloc(sizeof(SparseMatrix));

    // Set the row and column counts
    sm->rows = rows;
    sm->cols = cols;

    // Set how many non-zero elements we plan to have
    sm->nonZeroCount = nonZeroCount;

    // Allocate memory for the non-zero elements.
    // We do this once, knowing how many non-zero elements there are.
    sm->elements = (SparseElement *)malloc(nonZeroCount * sizeof(SparseElement));

    return sm; // Return the pointer to the newly created sparse matrix
}

// This function prints the sparse matrix in a human-readable form.
// Instead of printing all rows and columns, we just print the non-zero elements and their positions.
void printSparseMatrix(SparseMatrix *sm) {
    printf("Sparse Matrix:\n");
    // Loop through each non-zero element and print its row, column, and value.
    for (int i = 0; i < sm->nonZeroCount; i++) {
        printf("Row: %d, Col: %d, Value: %d\n",
            sm->elements[i].row,
            sm->elements[i].col,
            sm->elements[i].value);
    }
}

// This function frees all the allocated memory for the sparse matrix.
// Always free memory when you're done using it, to prevent memory leaks.
// In AI scenarios, especially with large data, proper memory management is crucial for scalability.
void freeSparseMatrix(SparseMatrix *sm) {
    // First free the array of non-zero elements
    free(sm->elements);
    // Then free the structure itself
    free(sm);
}

int main() {
    // We create a sparse matrix of size 5x5 with 3 non-zero elements.
    // Imagine a 5x5 matrix, which has 25 possible entries. We only have 3 that are non-zero.
    // This is a simple example, but in AI applications (like text data), 
    // you might have millions of entries with only a few thousand non-zero values.
    SparseMatrix *sm = createSparseMatrix(5, 5, 3);
    
    // Here we manually set the 3 non-zero elements.
    // Each element is defined by its (row, column, value).
    // For instance, the first element is at row 0, column 1, and has a value of 10.
    // These positions are 0-based indices.
    sm->elements[0] = (SparseElement){0, 1, 10};
    sm->elements[1] = (SparseElement){2, 3, 20};
    sm->elements[2] = (SparseElement){4, 0, 30};

    // Print the sparse matrix to confirm our data.
    // This shows which elements are non-zero and at what positions.
    printSparseMatrix(sm);

    // Free the memory once we are done.
    freeSparseMatrix(sm);

    return 0; // Return 0 indicates the program ended successfully.
}
