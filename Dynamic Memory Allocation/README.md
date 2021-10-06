# Dynamic Memory Allocation

- C gives the programmer the tools to allocate memory dynamically through several functions in `stdlib.h`
- Dynamic memory allocation is a powerful too which alows our programs to adapt to varying inputs, but it comes with increased development overhead
- Functions realated to dynamic memory allocation
  - `malloc`
  - `calloc`
  - `realloc`
  - `free`

## `malloc`

```c++
void * malloc(size_t size)
```

- Allocated size byted and returns a pointer to the allocated memory. Memory is __not__ initialized
- Function returns _* pointer_ to memory allocated
- If the system cannot allocate memory, `NULL` is returned
  - `NULL` is also returned if `size` is zero
- If you call `malloc` again for one pointer, you lose the pointer to the memory that was allocated, and you cannot free it later
- returns `NULL` if memory cannot be assigned (check after using)
- [malloc example](malloc_example.c)
- [memory leak](memory_leak.c)

## `calloc`

```c++
void * calloc(int nmemb, size_t size);
```

- Allocates memory for an _array_ of `nmemb` elements of `size` bytes each and returns a pointer to the memory
- initializes data to zeroes

## `realloc`

```c++
void * realloc(void *ptr, size_t size);
```

- Changes the size of the memory block points to by `ptr` to size btytes. If `ptr` is `NULL`  then the call is eq to `malloc`
- If the new size is bigger than the previous size, the new data is __not__ initialized

## `free`

- Frees the memory space pointed to by `ptr` which must have been returned by a previoud calls to `malloc`, `calloc`, or `realloc`

## Heap vs Stack

- The stack has several important props
  - linear data structure
  - high speed across
  - memory is not fragmented
  - Memory cannot be resized

- The heap differs from the stack in the following ways
  - Memory is resizebale using realloc
  - memory can be gragmented
  - developer is responsible for managing memory

## Void pointer

- Memory allocation funcitons like `malloc` reutrn `void *`
- This allows the returned block of memory to be reallocated to match the desired type

## Pointers and Storage

- It is possible to assign a pointer to another pointer, but remember that both pointers will then refer to the same location in memory
- This could cause unintended side effects in your program

## Dynamic MEmory and Files

- Dynamic memory allocation allows the developer to work with unknown file sizes and structures
- For example, when loading raw flight data, we do not know at compile time how many entries are in the file to be loaded. Dynamic memory allocation allows out programs to adapt to these conditions

## Valgrind

- Debugging and progiling tool for C and C++ programs
- One of the components, `memcheck`, is particularly useful for deugging memory leaks
- When using Valgrind, it is recommended to compile your program with the following flags
  - `-g` - includes debugging information so Valgrind can report exact lines
  - `O0` - removes optimization to improve the Valgrind's accuracy in reporting

### Using Valgrind
 
- If your program runs like this:
    - `program arg1`
- You run it using Valgrind like this:
    - `valgrind --leak-check=yes program arg1`