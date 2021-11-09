# Hash Maps

- A __hash map__ is an __abstract unordered associative array__ representing a mapping between a __key__ and a __value__
  - __Unordered__ - meaning the data is represented in no particular ordering
  - An __associative array__ is an array considering of key-value pairs for which each key is unique (e.g. IDs, Addressing, etc.)
- A key in a hash map need not be a numerical value
- It can be any variable sequence of characters
- A __hash function__ converts the sequence of characters to a numerical value which is used to determine the index
- __keys__ - the input before the hash function
- __buckets__ - where the hashed data is stored

## Basic implementation

- To implement a basic hash map, only need two components
    1. Hash function
    2. Array

## Resolving Collisions

- Often times multiple unique keys will map to the same bucket

  ### The Birthday Paradox

  [Birthday Paradox probability graph](Birthday_Paradox.png)

  - Only 23 people will reault in a 50% chance that two people will share the same birthday
  - If 60 people are sampled, there is a 99.4% chance
  - This shows that collisions are more common than you would think!
  - Scaling this, we find that with 1,000,000 buckets, there is a 95% chance that a collision will occur if onle 2,450 keys are hashed.

- Many ways to resolve collisions, but can be broadly grouped into one of two types:
  - __Seperate Chaining__
  - __Open Addressing__

### [Seperate Chaining](seperate_chaining.png)



- Solutions based on __seperate chaining__ use an additional data structure for each entry in the aray, such as a linked list
  - Many different data structure choices, but usually determined based on memory and compute time
- If a colision occurs at the same index, the item is added to a list associated with that bucket

#### Linked List

- If the data that is being stored is small, a linked list might not be a good choice as the overhead of the next pointer will add up
- [Seperate Chaining - Linked List Example](hash_map_ll.c)

#### Binary Search Tree

- Efficient search
- This method relies on the tree being balanced. This coupled with other operations like deletion can cause slowdowns depending on the implementation

#### Arrays

- Searching between multiple elements in the same bucket is linear with arrays
- When items are added or removed, the array needs to be resized
- This requires moving elements in the case of removing an item

### Open Addressing

- __Open addressing__ is arguable more common as it is much easier to implement
- The simplest version is called __linear probing__
  - If a collision occurs the table is linearly scanned until the desired entry is found OR an empty entry is found
  - most widely used in today's computers
- More chances for future collisions because hash map is used up faster

### Load Factor

- Can be characterized as that the most efficient bucket size to select
- The load factor can be computed as: 
  - __n/k__
  - _n_ is the number of entries in the hash table
  - _k_ is the number of buckets
- As the load factor increases, there are less buckets available per entry
  - Slows the lookup operation depends more on collision resolution
- A very los load factor is not necessarily beter than a finely tuned on
  - If there are many more buckets available than number of entries, the empty buckets are just wasted space
- The best load factor ususally depens on project requirements, but the goal is to keep the expected __constant time__ search property
- Some common implementation pick a load factor of around 0.7
- When the upper bound of the load factor is exceeded based on some insertion operation, the map must be resized and __rehashed__

### Rehashing

- Rehashing is required when the aray is resized
- The naive approach is to simply create a new array (usually fouble the size of the original) and copy all entried from the original array
- The issue with this method is that if the size of the array is large it can be very costly to write a table

#### All-At-Once Rehashing

- Rehashing the entire hash map
- Generally, the new number of buckets will be double the previous size

#### Incremental Rehashing

- Alternative to creating a new array each time it needs to be rehashed is to resize __incrementally__
- First, create a _new array_
- Original map should stay in memory and any new insertions should occur in the new array
- When an insertion occurs, move _r_ elements from the original array to the new one
- If the new array is (r + 1)/r times larger than the original, this will ensure the old array is completly copied before the new array needs to be resized
- During a search or deletion, each array is checked for the entry
- This must happen until all entries from the original have been mnoved over
- Once the original array is empty, it can be released