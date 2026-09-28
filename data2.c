#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int global_initialized = 150;   // Data segment
int global_uninitialized;       // BSS segment

int main() {
    int local_var = 30;         // Stack segment

    int *heap_var = malloc(sizeof(int)); // Heap segment

    if (heap_var == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    *heap_var = 500;

    printf("=== Memory Segment Addresses ===\n\n");

    printf("Global initialized (Data): %p\n",
           (void *)&global_initialized);

    printf("Global uninitialized (BSS): %p\n",
           (void *)&global_uninitialized);

    printf("Local variable (Stack): %p\n",
           (void *)&local_var);

    printf("Dynamic variable (Heap): %p\n",
           (void *)heap_var);

    uintptr_t stack_address = (uintptr_t)&local_var;
    uintptr_t heap_address = (uintptr_t)heap_var;

    unsigned long long difference;

    if (stack_address > heap_address) {
        difference =
            (unsigned long long)(stack_address - heap_address);
    } else {
        difference =
            (unsigned long long)(heap_address - stack_address);
    }

    printf("\nAddress difference between Stack and Heap: %llu bytes\n",
           difference);

    free(heap_var);

    return 0;
}
