# Stacks and Queues

## Stacks

- a stack is an abstract datatype that can be implemented with both arrays and linked lists
- It is restricted in how the data is accessed
- Stacks are manipulated using two core functions:
  - __Push__ - Adding an item to the stack
  - __Pop__ - Removing an item from the top of the stack

### LIFO Limitations

- This restriction of pushing and popping is referred to as Last In First Out (LIFO)
- This limitation implies that we can only ever access the last element pushed onto the stack

### Static Array Implementation

- A stack can be implemented in both a static or dynamic array
- For a static array, the size limits the number of items that can be pushed onto the stack
- An additional integar ia also necessary to indicate the position of the last element
- Given a array _A_ and an integer to the last element _i_:
  - To __push__ an item onto the stack, the item is simply inserted an the index referenced by _i_. The index is increased by 1. 
  - To __pop__ an item, the index is simply decreased by 1. It does not matter that the value still remains since the index determines what item to access

### Dynamic Array Implementation

- Requires more implementation of memory allocation
- Given an array _A_ and an integer to the last element _i_:
  - To __push__ an item onto the stack, we first allocate memory for the new item before inserting
  - When __popping__ an item, the array is reallocated to a smaller size
- [Example](dynamic_array_stack.c)

### Linked List Implementation

- _most efficient when keeping a reference to the last element_
- Given a linked list _L_:
  - To __push__ an item onto the stack, memory is allocated for a new node and added to the end of the list
  - To __pop__ an item off the stack, the last element is removed and the previous link in the list is set as the tail
- [Example](ll_stack.c)

## Queues

- Like stacks, only one element can be accessed at a time
- A __queue__ is defined as operating using a First In First Out (FIFO) paradigm 
- Two main operations for queues
  - __enqueue__ - Adding something to the end of the queue
  - __dequeue__ - Removing something from the fron of the queue

### Static Array Implementation

- Implementing these operations using arrays requires that all items in the queue be shifted as each item is added and removed
- This is not very efficient when compared to a linked list
- To __enqueue__ an item, the new element is simply added to the location referenced by the index. This index is then increased to reflect the new size
- To __dequeue__ an item, the element at the head of the list is first removed. All elements to the right of the first element must be shifted to the left. Finally, the index is decreased by 1.
- [Example](static_array_queue.c)

### Dynamic Array Implementation

- Besides the requirement of managing the allocated memory, there is not much difference when implementating a queue using dynamic arrays
- Given an array _A_ and size index _i_
  - To __enqueue__ an item, soace is first allocated in the array. The new element is then added to the location referenced by _i_. This index is then increaded to reflect the new size
  - To __dequeue__ an item, the element at the head of the list is first removed. All elements to the right of the first element must be shifted to the left. Finally, the index _i_ is decreased by 1
- [Example](dynamic_array_queue)

### Linked List Implementation

- A linked list is arguablly the most efficient structure when considering queues, dependent on how it is implemented 
- If an external reference to the head and tail is kept, __enqueue__ and __dequeue__ require minimal operations
- [Example](queue_doubly_linked_list.c)