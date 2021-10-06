# Intro to C

## What is C?

- Developed in bell labs
- _Imperative Language_
    - Written from top to bottom
    - Contrast with _declarative_
- Compiled language
    - Contrast with Interpreted
        - Python
        - JavaScript

## Why C?

- High Level language, but low compared to other high level languages
- Introduces concepts useful for future courses
    - Memory management
    - Pointers

## The First Program

```c++
#include <stdio.h>

// main function -- start of execution
int main() {
    float a = 6.2;
    printf("Hello CSE1320. 2+2=%f\n", a);

    return 0;
}
```

- Doesn't matter what main function returns. `0` is universal sign for nothing went wrong.

### Preprocessor Directives

- `#include <stdio.h>` - _preprocessor directive_
- `#define PI 3.14` lets you define a value

### Comments

```c++
// This is a comment
/* This is also a comment */
```

- Comments are ysed to enhance readability and understanding of code. They are ignored by the compiler.
- Don't need to add comments to self explinatory code, i.e. `is_odd();`

### The _main_ Function

```c++
int main(void) {
    return 0;
}
```

- `main()` is a function (think _f(x)_)
- Don't technically need one in C, but will need one if you want to run the program

## Types

- In C, each value has _type_. The vasic data types are
    - `int`
    - `float`
    - `char`

## ASCII characters and values

- 48 = '0'
- 65 = 'A'
- 97 = 'a'

## Output

```c++
printf("Hello CSE1320. 2+2=%f\n", a);
```

- https://en.wikipedia.org/wiki/C_data_types for string formatting
  - `int` is always is signed


## Compilation (not important to the class)

- Code is translated into a program through compilation
- 5 steps:

### Preprocessing

- Removes comments from the source file
- Expands macros 
- Expands included header files
- Injects definition values

### Translating

- Translates the output of preprocessing into assembly language
- The assembly language is dependent on the platform
    - Intel
    - ARM
    - Etc...

### Optimization

- Inlining -Removes function call overhead
- Loop Unrolling
    - Removes Instructions that control the loop
    - Removes end of loop tests
    - Reduces branch penalties
    - Increases the binary size

### Assembling

- Converts assembly code in maching code (binary)
    - Also known as _object code_
- If multiple files are present, multiple objects are created

### Linking

- Merges object code from multiple objects
- Links library functions
- Static linking


## Input and Output Variables

- Useful to read input frim the keyboard or other programs
- `printf();`
  - used for printing to stdout
  - first argument is the control string
- `scanf();`
  - not ideal for reading strings
- _Stack smashing_ is when the program attempts to write to memory locations not assigned to the stack
- `fgets();` best for reading in data more than a single character
  
### Formatting

```c++
"%-015.1f"
```

- `%` initiates formatting
- `-` right justify. Left justify by default
- `0` pads with zeroes
- `15` reserves 15 spaces to output number
- `.1` uses only one number after decimal
- `f` formats a floating point number and ends formatting