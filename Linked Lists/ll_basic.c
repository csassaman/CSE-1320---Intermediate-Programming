#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node {
    int val;
    node *next;
    node data;
};

node *add_node(double data) {
    node *n = calloc(1, sizeof(node));
    if (n) {
        n->data = data;
    }

    return n;
}

void traverse(node *n) {
    if (n != NULL) {
        printf("%.2lf\n", n->data);
    }
}

void release();

node *reverse(node *n) { // pointer represents the head of the list
    node *current;
    node *prev = NULL;
    node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current; 
        current = next;
    }

    return prev;
}

int main() {
    node *head = add_node(0);
    node *tail = head;

    for (int i = 1; i <= 10; i++) {
        tail->next = add_node(i);
        tail = tail->next;
    }

    traverse(head);

    head = reverse(head);

    traverse(head);

    return 0;
}

// int main() {
//     node *head = calloc(1, sizeof(node));
//     head->val = 100;
    
//     node *temp = NULL;
    
//     for (int i = 0; i <= 10; i++) {
//         temp = calloc(1, sizeof(node));
//         temp->val = 1;
//         temp->next = head;
//         head = temp;
//     }

//     return 0;
// }