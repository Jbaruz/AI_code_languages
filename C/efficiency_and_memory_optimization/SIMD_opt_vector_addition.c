// SIMD Optimization for Vector Addition
// Use SIMD (Single Instruction Multiple Data) for parallel computations,
// crucial in AI for vectorized operations.
// Author: JBA
// Date: 08-12-2024

#include <stdio.h>
#include <emmintrin.h> // This header gives us access to SSE intrinsics for vector operations

// This function performs vector addition using SIMD instructions (Single Instruction, Multiple Data).
// For AI learners: Modern AI computations often involve huge amounts of numeric operations on large arrays (tensors).
// Using vectorized (SIMD) instructions can speed up these operations significantly by handling multiple elements at once.
//
// Here, we add two arrays 'a' and 'b' of floats element-wise and store the result in 'result'.
// Instead of adding elements one by one, we use CPU instructions that can add multiple elements in parallel.
void vectorAddition(float *a, float *b, float *result, int n) {
    // We'll increment i by 4 each time since we process 4 float elements at once.
    for (int i = 0; i < n; i += 4) {
        // __m128 is a special data type representing a 128-bit vector that can hold 4 floats.
        // _mm_loadu_ps loads 4 floats from memory (from array 'a' starting at &a[i]) into a __m128 register.
        __m128 va = _mm_loadu_ps(&a[i]); // Load 4 floats from array a
        __m128 vb = _mm_loadu_ps(&b[i]); // Load 4 floats from array b
        
        // _mm_add_ps performs an element-wise addition of the two __m128 vectors 'va' and 'vb'.
        // It produces another __m128 with the sum of corresponding elements.
        __m128 vr = _mm_add_ps(va, vb);  // Perform vector addition on 4 elements at once

        // _mm_storeu_ps stores the 4 floats from the __m128 'vr' back into the result array.
        _mm_storeu_ps(&result[i], vr);   // Store the result back into the result array
    }
}

int main() {
    int n = 8;  // Size of the vectors. We have 8 elements in 'a' and 'b'.
                // In AI, arrays (or tensors) can be much larger. But this example demonstrates the concept.
    float a[8] = {1, 2, 3, 4, 5, 6, 7, 8}; // Input vector a
    float b[8] = {8, 7, 6, 5, 4, 3, 2, 1}; // Input vector b
    float result[8]; // This array will hold the result of a[i] + b[i] for each i

    // Call our vectorized addition function.
    // After this call, 'result' should contain {9, 9, 9, 9, 9, 9, 9, 9}.
    // Notice how easily we can get these results, and if we had a much larger 'n',
    // the SIMD operations would help achieve better performance compared to a basic for loop.
    vectorAddition(a, b, result, n);

    // Print the result vector to verify the operation.
    // In practice, for AI tasks, you might not print values, but instead feed these results into further computations.
    printf("Result Vector:\n");
    for (int i = 0; i < n; ++i) {
        printf("%.2f ", result[i]);
    }
    printf("\n");

    return 0; // Indicate successful program termination
}

// In summary, this code uses Intel's SSE instructions to add vectors efficiently.
// Such vectorization techniques are widely used in AI and machine learning 
// frameworks to accelerate linear algebra and other numerical operations on large datasets.


