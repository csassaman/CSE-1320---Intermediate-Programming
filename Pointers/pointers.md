# Pointers

## Pointers vs Addresses

### Addressing

A program keeps tracks of memory using an addressing system. 
Some systems address each byte and are called __byte-addressable__ computers
Other are __word-addressable__
- __byte-addressable__
  - individual bytes are addressed
- __word-addressable__
  - _word_ is a chunk of memory, think 32-bit, 64-bit processors, etc.
  - defined in the arcetectute size

When a program is executed and loads into memory, the loader determines where in memory the values of each variable are stores

In C, we can determine the address of any variable using the & operator

### Pointers

- Interchangeable with address
- The & operator converts the variable to a different type called a __pointer__
- A __pointer__ variable stores the address of a memory location 
- __Note: This address is considered a value__

- In C, every data type has a corresponding __pointer-to__ type
- To decalre a pointer, add an asterisk before the __identifier_
- Every datatype has its own pointer
  - `int *intptr`
  - `char *charptr`
  - `*` is type operator

## Pointer Arithmetic

- Pointer arithmetic permits addition between a pointer and an integer
- When adding integer to a pointer, C adds the integer * the number of bytes of the underlying datatype
- Really only preavelent in C language

```c++
int *ptr;
//increases the address by k * sizeof(int) bytes
ptr += k;
```

## Dereferencing Pointers

- The address is useful for knowing where the values is stroed, __but how do we get the value stored at a particular address?__
  - C permits this thrugh __dereferencing__

```c++
int a = 5;
int *ptr = &a;
printf("%d", *ptr);
```

## Assiging Manual Locations

- It is possible to assign a memory location to a pointer manually (typically bad)
-  `int *ptr = (int *) 4;` --> casting 4 as an integer pointer
- However, the operating system may not allow the program to alter the contents at that memory location.

## Default Assignment 

- It is good practice to assign `NULL` to pointer declrations
- `NULL` is defined in most of the standard library headers , including stdio.h

## Debugging with Addresses

- Memory issues can be some of the most difficult issues to debug in C.
- These runtime issues are not detected during compilation, but can lead to strange side effects
- If `ptr` is initilized as `NULL`, you can guard any segmentation faults but guarding with an if statement:

```c++
if (ptr) {
  // do something with pointer
}
```

## Arrays and Pointers

- The name of an array points to the address of the first object in the array
- We can use potiner arithmeticto move to subsequence addresses

```c++
char arr[] = { 'a', 'b', 'c', 'd' };
char *c_ptr = arr + 2;
char c = *c_ptr; //'c'
```

## Strings and Pointers

- Using pointer notation with strings is very similar to using pointers with arrays
- The identifier of the string is a pointer to the first character in the string
- Basically everything in `string.h` uses character pointers as inputs to functions
- __`char *str2 = str1;` will only copy the address of the original pointer (shallow copy)__
  - need to use `strcpy()` to completely copy string to another variable

```c++
// String initilization
int main() {
  char str1[10] = "Hello!\n";
  char *str2 = str1; // only copies address of str1 to str2 pointer

  printf("%s", str); // pointer to first character of str array

  return 0;
}
```

```c++
/* 
 * String Tokenization
 */
int main() {
  char csv_line[128] = "NAME,ID,AGE";

  // will modify string by replacing the token with a null character
  char *token = strtok(csv_line, ","); 

  int token_count = 0;

  while (token != NULL) {
    printf("token %d: %s\n", token_count + 1, token);

    token_count++;

    token = strtok(NULL, ",");
  }

  return 0;
}
```

## String Literals vs. Character Arrrays

### Character Array

```c++
// Characcter Array
char arr[] = "char array.";
```

- Creates a `char` array object _arr_ and initializes it with the string literal "char array."
- Modifiable

### String Literal

```c++
//String Literal
char *arr_ptr = "String literal.";
```

- Points to an object with type "array or `char`" whose elements are initialized with a string literal
- Any attempt to modify the array pointed to by `arr_ptr` is undefined
- __Not__ modifiable

## Pointer Arithmetic for 2D Arrays

Take a 2d array for example. Dereferencing the pointer to the array points to the address of the first row. Dereferencing again, i.e. `**arr2d` provides the value of the first entry of the first row.

```c++
char arr2d[10][10];
char *ptr1 = *arr2d;
ptr1 = *(arr2d + 1);
*ptr1 = *(arr2d + 1);
```

## Double Indirection and Arrays


```c++
// Double indirection
int a = 10;
int *b = &a;
int **c = &b;
```

## Memory Layout of Static Arrays

- This is similar to 2D array in some respects, but the memory layout between pointers-to-pointers and a static 2D array is different
- Recall that when an array is created in C, the values or the array are guaranteed to be contiguous in memory
- A 2 X 2 array of pointer-to-`int` might have the following layout

|Location|Value|
|--------|-----|
|0|1000|
|8|2000|
|16|3000|
|24|4000|

- The values are addressesof each integer

## Pointers to Functions

- Just as each variable identifier has an address associated with it, the identifier of a function also has an address
- This address represents the location of the execution code for that function
- The fact that the identifier is an address means that we can declare a pointer to a function returning any type
- The value of such a pointer would be the address pointing to the execution code of the function

```c++
// syntax
int (*fn_ptr)(int a); // pointer to function that returns int
```

- Parentheses are to indicate we are talking about a function pointer
- Removing the deregerence operator leaves a pointer to a function that returns an `int`  and accepts an `int` as input
- [function_pointer.c](function_pointer.c)
- [operator_ptr_return.c](operator_ptr_return.c)

### `qsort`

```c++
void qsort(void *base, size_t num, size_t width,
           int (*compar)(const void *, const void *));
```

- `qsort` is a function from the standard C library which implements the quick sort algorithm
- The first three parameters relate to the values of objects to be sorted
  - `base` - The array of elements
  - `num` - The number of elements in the array
  - `width` - The byte suze of each element
- The fourth argument is a function pointer which is used to compare two elements in the array. this will be defined depending on the application
- The input type for this comparison function is `void *` so that it can handle any data type
- The comparison functio nmust return an integer less than, equal to, or greater than zero if the first argument is considered to be respectively less than, equal to ,m or greater than the second
- If two members are equal, their relative order is undefined

## Command Line Arguments

- Programs can be more general by accepting parameters from the command line
- `main()` function accepts two formal argumenets
  - `int argc` as the number of arguments
  - `char **argv` stores each individual command line argument, where an argument is separated by a space
- 