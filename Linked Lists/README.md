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

## Efficiency Analysis

### Indexing

- An array member can be acessed in constant time
- For a linked list, the node must be found by cycling through the list. In the worst case, it will take as many cycles as there are nodes
- Slower than accessing it directly

### Insert/Delete at Beginning

- Constant time operation
- Since the first node is always know, this can be done in constant time by simply removing the head

### Inserting/deleting at the End

- Still only a single operation for linked lists, but the list must still be traversed to find the end

### Memory Considerations

- In its most basic form, each node of a linked list requires space for the struct node which includes whatever datatype the value is. For example, using 8 byte address, a node which contains a single character requires 9 bytes
- A similar array would requere 9 times less memory

