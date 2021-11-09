#include <stdio.h>

#define QUEUE_CAPACITY 64

void enqueue(int queue[], int *size, int data) {
    if (*size == QUEUE_CAPACITY) {
        printf("Queue is full!\n");
        return;
    }

    // Shift data to the right.
    for (int i = *size; i > 0; i--) {
        queue[i] = queue[i - 1];
    }

    queue[0] = data;

    (*size)++;
}

int dequeue(int queue[], int *size) {
    if (*size == 0) {
        printf("Nothing to dequeue!\n");
        return 0;
    }

    (*size)--;

    return queue[*size];
}

void print_queue(int queue[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\n", queue[i]);
    }
}

int main() {
    int queue[QUEUE_CAPACITY] = { 0 };
    int size = 0;

    enqueue(queue, &size, 1);
    enqueue(queue, &size, 2);
    enqueue(queue, &size, 3);

    print_queue(queue, size);

    printf("Dequeuing...\n");

    dequeue(queue, &size);

    print_queue(queue, size);

    return 0;
}