# Stacks and Queues

- Stacks - first in last out
- Queues - first in first out
- Abstract datatypes

## Stacks

- Can be implemented with both arrays and linked lists
- Operations
  - __Push__
  - __Pop__

### LIFO Limitations

### Static Array Implementation

- A stack can be implemented in both a static or dynamic array
- For a static array, the size limits the number of items that can be pushed onto the stack
- An additional integar ia also necessary to indicate the position of the last element
- Given a arrayk _A_ and an integer to the last element _i_:
  - To __push__ an item onto the stack, the item is simply inserted an the index referenced by _i_. The index is increased by 1. 
  - To __pop__ an item, the index is simply decreased by 1. It does not matter that the value still remains since the index determines what item to access

### Dynamic Array Implementation

- Requires more implementation of memory allocation

## Queues

- A queue is defined as operating using a First In First Out (FIFO) paradigm 
- Two main operations for queues
  - __enqueue__ - Adding something on the queue
  - __dequeue__

### Static Array Implementation

- Implementing these operations using arrays requires that all items in the queue be shifted as each item is added and removed
- This is not very efficient when compared to a linked list
- To __enqueue__ an item, the new element is simply added to the location referenced by the index. This index is then increased to reflect the new size
-  To __dequeue__ an item, the element at the head of the list is first removed. All elements to the right of the first element must be shifted to the left. Finally, the index is decreased by 1.

