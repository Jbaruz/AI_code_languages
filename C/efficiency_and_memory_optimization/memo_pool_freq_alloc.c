// Memory Pool fot frequent allocations - C programming
// Avoiding frequent mallo calls improves efficiency in systems like AI models
// that repreatedly allocate/deallocate memory.
// Author: JBA
// Date: 08-12-2024

#include <stdio.h>
#include <stdlib.h>

// This code implements a simple memory pool allocator.
// Instead of calling 'malloc' multiple times for many small allocations, we allocate one large chunk of memory at the start (the pool)
// and then give out pieces of it as needed. This can reduce overhead and fragmentation, which can be important in performance-critical 
// AI or data processing scenarios where large amounts of memory are allocated frequently.

// The MemoryPool struct tracks:
// - 'pool': A pointer to the big block of allocated memory.
// - 'size': The total size of this block.
// - 'used': How much of this block we have currently allocated.
typedef struct MemoryPool {
    char *pool;    // The memory block
    size_t size;   // Total size of the block in bytes
    size_t used;   // How many bytes have been used so far
} MemoryPool;

// createMemoryPool:
// This function creates a new memory pool by allocating a big chunk of memory of the given 'size'.
// In AI contexts, you might use a memory pool for operations where you know in advance how much memory 
// you need and want faster memory allocations without fragmentation.
MemoryPool *createMemoryPool(size_t size) {
    MemoryPool *mp = (MemoryPool *)malloc(sizeof(MemoryPool));
    mp->pool = (char *)malloc(size); // Allocate one large block
    mp->size = size;
    mp->used = 0; // Nothing allocated yet
    return mp;
}

// allocateFromPool:
// Instead of calling 'malloc', we just move forward in our pre-allocated block.
// 'size' is how many bytes we want. If we have enough space left in the pool, we return a pointer 
// to the correct place within 'pool' and increase 'used' by that amount. If not, we print an error and return NULL.
// For AI tasks, this can speed up memory management for large data structures or temporary buffers.
void *allocateFromPool(MemoryPool *mp, size_t size) {
    // Check if we have enough space left
    if (mp->used + size > mp->size) {
        // Not enough space left in the pool
        printf("Memory pool exhausted!\n");
        return NULL;
    }
    // 'mem' points to the next free byte in the pool.
    void *mem = mp->pool + mp->used;
    // Advance the 'used' pointer by 'size' bytes
    mp->used += size;
    // Return the pointer to this newly "allocated" chunk
    return mem;
}

// freeMemoryPool:
// Frees all the memory associated with the memory pool.
// Notice that we do not free individual allocations, as the pool is meant to be freed all at once at the end.
// This simplifies memory management in complex AI pipelines where you allocate a bunch of temporary data 
// and then discard it all at once.
void freeMemoryPool(MemoryPool *mp) {
    // Free the large block
    free(mp->pool);
    // Free the memory pool structure itself
    free(mp);
}

int main() {
    size_t poolSize = 1024; // 1KB pool: This is small for demonstration. In AI, you might have MBs or GBs.

    // Create a memory pool of the specified size
    MemoryPool *mp = createMemoryPool(poolSize);
    
    // Allocate space for an integer array of size 10 from the pool
    int *arr = (int *)allocateFromPool(mp, 10 * sizeof(int));
    if (arr) {
        // If allocation succeeded, use 'arr' as a regular array
        for (int i = 0; i < 10; ++i) {
            arr[i] = i * i; // Store the square of i
            printf("%d ", arr[i]); // Print it out
        }
        printf("\n");
    }

    // After we are done using the pool and everything it allocated, 
    // we release the entire pool in one go.
    freeMemoryPool(mp);

    return 0;
}

// In summary, this code:
// - Allocates a single large memory block upfront (memory pool).
// - Distributes this memory upon request without calling malloc repeatedly.
// - Frees everything at once at the end.
//
// In AI systems, managing memory efficiently is critical, especially when dealing with large models and datasets. 
// A memory pool can help reduce overhead and fragmentation, leading to more predictable performance.
