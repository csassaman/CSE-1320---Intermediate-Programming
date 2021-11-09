# Macros

- Anything that starts with `#define` 
- Can also be functions
    ```c
    #define MIN(a, b) a < b ? a : b

    #define MAX(a, b) a > b ? a : b
    ```
- Can be much more efficient, but not a replacement to functions