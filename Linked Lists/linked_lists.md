# Linked Lists

- A linked list is defined as a linear sequence of connected nodes
- In its most basic form, each node has a pointer to the subsequent node
- A mode of a linked list is implemented as a struct
    ```c++
    struct node {
        int val;
        struct node *first;
        struct node *previous;
        struct node *next;
        struct node *last;
    };
    ```
- node in linked lists can be moved and rearranged by changing the pointers
- __Have a reference to the data before you change it 

## Inserting

- A node is inserted by first allocating memory fo rthe node itself and then setting the pointer of the previous node

## Removing

- A node is removed by freeing the memory allocated to the node and modifying any dependent nodes 
    ```c++
    free(b);
    a->next = NULL;
    ```
- If the node being removed has dependents of its own, those links are updated as well
- For example, given a linked list a->b->c and a removal of b:
    ```c++
    a->next = b->next;
    free(b);
    ```
