# Into to C++

- Began as a superset of C which included the concept of a _class_
- Classes provide a multitude of features for user-defined types, abstration, and modularity
- Since its inception, C++ has gone thorugh several iterations
- This class will touch only on the C11 standard

## Transitioning from C

- Any finction written in C can be written in C++
- Part of programming in C++ means adhearing to modern standards and practives

## The first program

```c++
#include <iostream>

int main {
    std::cout << "Hello, CSE1320.\n";
}
```

# Types

- `auto` type automatically initializes to correct type

# `range-for` loop

```c++
int arr[] = {0, 1, 2, 3, 4, 5, 6};

for (auto val : arr) {
    std::cout << val << std::endl;
}
```

```c++
for (auto& val : arr) {
    std::cout << val << std::endl; //no need to deference
}
```

## Pointers

- Goal is not to use them
- Practices for using them have changed greatly
- `nullptr`

## the `vector`

- With the addition of classes comes a useful implementation: the `vector` class
- This is a general aggregate type that is used to represent a collection of any type, even user-defined types
  - Dynamic collection of objects
- `std::vector<double> v({1,1m 2m 3.2});`
  - This created a collection of type `double` with 3 values
- Manages its own memory

## General Advice

- C++ is not C with classes
- not optimal to write C code within C++
- Avoid pointer arithmetic if necessary
- Stick to C++ `strings` and `vectors`

# Handling Dynamic Memory in C++

## No More `*alloc`

- `new` and `delete`

```c++
double *a = new double[100];

for (int i = 0; 1 < 100; i++) {
    a[i] = i;
}

delete a;
```

## Smart Pointers

- C++ offers several ways of sefely handling pointers

- [`unique_ptr`](unique_ptr.cpp)
- `shared_ptr`

- C++ allows overloading functions: same function names with different number of variables

# File I/O

- Formatted input and output is provided by the `iostream` library
- Other useful stream libraries such as one for working with files

## Output

- the `<<` ("put to") operator works with objects of type `ostream` 
- Compuex outputs can be combined using the << operator

## Input

```c++
getline();
```
