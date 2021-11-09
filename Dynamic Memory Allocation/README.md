# Dynamic Memory Allocation

- C gives the programmer the tools to allocate memory dynamically through several functions in `stdlib.h`
- Dynamic memory allocation is a powerful tool which allows our programs to adapt to varying inputs, but it comes with increased development overhead
- Functions realated to dynamic memory allocation
  - `malloc`
  - `calloc`
  - `realloc`
  - `free`

## `malloc`

```c++
void * malloc(size_t size)
```

- Allocated `size` bytes and returns a pointer to the allocated memory. Memory is __not__ initialized
- Function returns _* pointer_ to allocated memory
- If the system cannot allocate memory, `NULL` is returned
  - `NULL` is also returned if `size` is zero
- If you call `malloc` again for one pointer, you lose the pointer to the memory that was allocated, and you cannot free it later
- [malloc example](malloc_example.c)
- [memory leak](memory_leak.c)

## `calloc`

```c++
void * calloc(int nmemb, size_t size);
```

- Allocates memory for an _array_ of `nmemb` elements of `size` bytes each and returns a pointer to the memory
- initializes data to zeroes
  - Cannot initialize data to anything other than zero since the function does not know the underlying datatype and bit structure

## `realloc`

```c++
void * realloc(void *ptr, size_t size);
```

- Changes the size of the memory block pointed to by `*ptr` to size btytes. If `ptr` is `NULL`  then the call is eq to `malloc`
- If the new size is bigger than the previous size, the new data is __not__ initialized

## `free`

```c++
void free(void *ptr);
```

- Frees the memory space pointed to by `ptr` which must have been returned by a previoud calls to `malloc`, `calloc`, or `realloc`

## Heap vs Stack

- The __stack__ has several important properties
  - Linear data structure
  - High speed access
  - Memory is not fragmented
  - Memory cannot be resized

- The __heap__ differs from the stack in the following ways
  - Memory is resizebale using `realloc`
  - Memory can be fragmented
  - Developer is responsible for managing memory

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
    - `valgrind --leak-check=full program arg1`
    - `--show-leak-kinds=all`