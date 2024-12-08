// Memory Pool fot frequent allocations - C programming
// Avoiding frequent mallo calls improves efficiency in systems like AI models
// that repreatedly allocate/deallocate memory.
// Author: JBA
// Date: 08-12-2024

#include <stdio.h>
#include <stdlib.h>

typedef struct MemoryPool {
    char *pool;
    size_t size;
    size_t used;
} MemoryPool;

MemoryPool *createMemoryPool(size_t size) {
    MemoryPool *mp = (MemoryPool *)malloc(sizeof(MemoryPool));
    mp->pool = (char *)malloc(size);
    mp->size = size;
    mp->used = 0;
    return mp;
}

void *allocateFromPool(MemoryPool *mp, size_t size) {
    if (mp->used + size > mp->size) {
        printf("Memory pool exhausted!\n");
        return NULL;
    }
    void *mem = mp->pool + mp->used;
    mp->used += size;
    return mem;
}

void freeMemoryPool(MemoryPool *mp) {
    free(mp->pool);
    free(mp);
}

int main() {
    size_t poolSize = 1024; // 1KB pool
    MemoryPool *mp = createMemoryPool(poolSize);
    
    int *arr = (int *)allocateFromPool(mp, 10 * sizeof(int));
    if (arr) {
        for (int i = 0; i < 10; ++i) {
            arr[i] = i * i;
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    freeMemoryPool(mp);
    return 0;
}

// Reduces fragmentation by preallocation a memory block.
// Faster allocation than standard malloc.