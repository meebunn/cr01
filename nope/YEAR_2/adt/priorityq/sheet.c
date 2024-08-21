void update_key(heap_t *heap, int old_key, int new_key) {
    // Find the index of the element with the old key
    int index = -1;
    for (int i = 1; i <= heap->last_index; i++) {
        if (heap->data[i] == old_key) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Element with old key %d not found.\n", old_key);
        return;
    }

    // Update the key with the new value
    heap->data[index] = new_key;

    // Adjust the heap to maintain the max heap property
    while (index > 1 && heap->data[index] > heap->data[index / 2]) {
        // Swap the element with its parent if it violates the max heap property
        int parent_index = index / 2;
        int temp = heap->data[index];
        heap->data[index] = heap->data[parent_index];
        heap->data[parent_index] = temp;
        index = parent_index;
    }
}