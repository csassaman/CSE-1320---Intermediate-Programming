#include <stdio.h>

#define QUEUE_CAPACITY 64

void enqueue(int queue[], int *size, int data) {
    if (*size == QUEUE_CAPACITY) {
        printf("Queue is full!\n");
        return;
    }

    //shift data to the right.
    for (int i = *size; i > 0; i--) {
        queue[i] = queue[i - 1];

    }

    queue[0] = data;

    (*size)--;
}

int dequeue(int queue[], int *size) {
    (*size)--;

    return queue[*size];
}

void print_queue(int queue[], int size) {
    // Print queue
}

int main() {

}