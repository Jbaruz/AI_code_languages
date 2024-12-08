// SIMD Optimization for Vector Addition
// Use SIMD (Single Instruction Multiple Data) for parallel computations,
// crucial in AI for vectorized operations.
// Author: JBA
// Date: 08-12-2024

#include <stdio.h>
#include <emmintrin.h> // For SMID instructions

void vectorAddition(float *a, float *b, float *result, int n) {
    for (int i = 0; i < n; i += 4) { // Process 4 elements at a time
        __m128 va = _mm_loadu_ps(&a[i]); // Load 4 floats from array a
        __m128 vb = _mm_loadu_ps(&b[i]); // Load 4 floats from array b
        __m128 vr = _mm_add_ps(va, vb); // Perform vector addition
        _mm_storeu_ps(&result[i], vr); // Store the result
    }
}

int main() {
    int n = 8; // Vector size
    float a[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    float b[8] = {8, 7, 6, 5, 4, 3, 2, 1};
    float result[8];

    vectorAddition(a, b, result, n);

    printf("Result Vector:\n");
    for (int i = 0; i < n; ++i) {
        printf("%.2f ", result[i]);
    }
    printf("\n");

    return 0;
}
// Uses Intel's SMID intrinsics for vectorized operations, improving performance.
// Essential for high-performance AI tasks like tensor operations.

