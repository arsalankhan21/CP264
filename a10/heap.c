/*
-------------------------------------------------------
Project:  cp264oc-a10q3
Author:   Arsalan Khan
Version:  2023-07-28
-------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"

HEAP *new_heap(int capacity) {
    HEAP *heap = (HEAP *)malloc(sizeof(HEAP));
    if (heap == NULL) {
        fprintf(stderr, "Memory allocation error while creating the heap.\n");
        exit(EXIT_FAILURE);
    }

    heap->capacity = (capacity < MIN_CAPACITY) ? MIN_CAPACITY : capacity;
    heap->size = 0;

    heap->hna = (HNODE *)malloc(heap->capacity * sizeof(HNODE));
    if (heap->hna == NULL) {
        fprintf(stderr, "Memory allocation error while creating the heap nodes array.\n");
        free(heap);
        exit(EXIT_FAILURE);
    }

    return heap;
}

void insert(HEAP *heap, HNODE new_node) {
    if (heap->size >= heap->capacity) {
        // If the heap is already full, increase its capacity
        unsigned int new_capacity = heap->capacity * 2;
        HNODE *new_hna = (HNODE *)realloc(heap->hna, new_capacity * sizeof(HNODE));
        if (new_hna == NULL) {
            fprintf(stderr, "Memory allocation error while resizing the heap nodes array.\n");
            return;
        }
        heap->hna = new_hna;
        heap->capacity = new_capacity;
    }

    // Insert the new node at the end of the heap
    unsigned int index = heap->size;
    heap->hna[index] = new_node;
    heap->size++;

    // Perform up-heap (bubble-up) to maintain the heap property
    while (index > 0) {
        unsigned int parent = (index - 1) / 2;
        if (cmp(heap->hna[index].key, heap->hna[parent].key) < 0) {
            // Swap the nodes
            HNODE temp = heap->hna[index];
            heap->hna[index] = heap->hna[parent];
            heap->hna[parent] = temp;
            index = parent;
        } else {
            break; // Heap property is restored
        }
    }
}

HNODE extract_min(HEAP *heap) {
    if (heap->size == 0) {
        fprintf(stderr, "Heap is empty. Cannot extract minimum element.\n");
        exit(EXIT_FAILURE);
    }

    // Extract the minimum element (root) of the heap
    HNODE min_node = heap->hna[0];

    // Move the last element to the root and decrease the size
    heap->size--;
    heap->hna[0] = heap->hna[heap->size];

    // Perform down-heap (bubble-down) to maintain the heap property
    unsigned int index = 0;
    while (1) {
        unsigned int left_child = 2 * index + 1;
        unsigned int right_child = 2 * index + 2;
        unsigned int smallest = index;

        if (left_child < heap->size && cmp(heap->hna[left_child].key, heap->hna[smallest].key) < 0) {
            smallest = left_child;
        }

        if (right_child < heap->size && cmp(heap->hna[right_child].key, heap->hna[smallest].key) < 0) {
            smallest = right_child;
        }

        if (smallest != index) {
            // Swap the nodes
            HNODE temp = heap->hna[index];
            heap->hna[index] = heap->hna[smallest];
            heap->hna[smallest] = temp;
            index = smallest;
        } else {
            break; // Heap property is restored
        }
    }

    return min_node;
}

int change_key(HEAP *heap, int index, KEYTYPE new_key) {
    if (index < 0 || index >= heap->size) {
        fprintf(stderr, "Invalid index for change_key operation.\n");
        return 0;
    }

    if (cmp(new_key, heap->hna[index].key) == 0) {
        // If the new key is the same as the current key, no change is needed
        return 1;
    } else if (cmp(new_key, heap->hna[index].key) < 0) {
        // The new key is smaller, perform up-heap (bubble-up)
        heap->hna[index].key = new_key;
        while (index > 0) {
            unsigned int parent = (index - 1) / 2;
            if (cmp(heap->hna[index].key, heap->hna[parent].key) < 0) {
                // Swap the nodes
                HNODE temp = heap->hna[index];
                heap->hna[index] = heap->hna[parent];
                heap->hna[parent] = temp;
                index = parent;
            } else {
                break; // Heap property is restored
            }
        }
        return 1;
    } else {
        // The new key is larger, perform down-heap (bubble-down)
        heap->hna[index].key = new_key;
        while (1) {
            unsigned int left_child = 2 * index + 1;
            unsigned int right_child = 2 * index + 2;
            unsigned int smallest = index;

            if (left_child < heap->size && cmp(heap->hna[left_child].key, heap->hna[smallest].key) < 0) {
                smallest = left_child;
            }

            if (right_child < heap->size && cmp(heap->hna[right_child].key, heap->hna[smallest].key) < 0) {
                smallest = right_child;
            }

            if (smallest != index) {
                // Swap the nodes
                HNODE temp = heap->hna[index];
                heap->hna[index] = heap->hna[smallest];
                heap->hna[smallest] = temp;
                index = smallest;
            } else {
                break; // Heap property is restored
            }
        }
        return 1;
    }
}

int find_data_index(HEAP *heap, DATA data) {
    for (int i = 0; i < heap->size; i++) {
        if (heap->hna[i].data == data) {
            return i; // Found the data in the heap
        }
    }
    return -1; // Data not found in the heap
}

int cmp(KEYTYPE a, KEYTYPE b) {
    // This is a simple comparison function.
    // Modify it based on your specific needs.
    if (a < b) return -1;
    if (a > b) return 1;
    return 0;
}
