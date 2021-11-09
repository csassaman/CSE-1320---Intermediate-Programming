# Linked Lists

- A linked list is defined as a linear sequence of connected nodes
- In its most basic form, each node has a pointer to the subsequent node
- A node of a linked list is implemented as a struct with a valie of any type, even complex type like another `struct`, allowing the list to grow dynamically
    ```c++
    struct node {
        int val;
        struct node *next; // points to next node in list, with last node being NULL

        // Other potential pointer variables
        struct node *first;
        struct node *previous;
        struct node *last;
    };
    ```
- Nodes in linked lists can be moved and rearranged by changing the pointers
- It is always important to __have a reference to the data before you change it__ to avoid losing your data

## Inserting

```c++
struct node *a = malloc(sizeof(struct node*));
struct node *b = malloc(sizeof(struct node*));
a->next = b;
```

- A node is inserted by first allocating memory for the node itself and then setting the pointer of the previous node

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

### [Some Basic Linked List Funtions](ll_basics.c)

## Efficiency Analysis

Compared to an array, how effiecient is each operation of a linked list?

### Indexing

- An array member can be acessed in constant time (e.g. `arr[i]`)
- For a linked list, the node must be found by cycling through the list. In the worst case, it will take as many cycles as there are nodes
- _Slower than accessing it directly_

### Insert/Delete at the Beginning

- __Constant time operation__
- Since the first node is always known, this can be done in constant time by simply adding the node and updating the `next` pointer
- A fixed array cannot preform this operation and a dynamic array must reallocate the memory, move all members forward by 1, and then instert the new data

### Inserting/Deleting at the End

- Still only a single operation for linked lists, but the list must still be traversed to find the end before adding a new node
- For an array, once new memory is allocated, the new data can be added in a single operation

### Memory Considerations

- In its most basic form, each node of a linked list requires space for the `struct node` which includes whatever datatype the value is. For example, using 8 byte address, a node which contains a single character requires 9 bytes
- A similar array would requere 9 times less memory to represent the same data