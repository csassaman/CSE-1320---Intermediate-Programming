# Enumerated Types

- Scalar types (single values, as opposed to aggregate types)
- These types are used often with structs and improve readability and structure of a program
- They are analagous to created multiple constants with either `const` or the `define` preprocessor
- Defined using the keyword `enum`
    ```c++
    enum boolean {
        false,
        true
    };
    ```
    ```c++
    // Can also specify scalar values for each constant
    enum http_status {
        OK = 200,
        MOVED_PERMANENTLY = 301,
        BAD_REQUEST = 400,
        FORBIDDEN = 403,
        NOT_FOUND = 404
    };
    ```
- Unless specified, the values defined in an `enum` take on sequential values starting from 0
- Once defined, variables can be created with enuymerated types
    ```c++
    enum boolean is_prime = false;
    ```
- A variable of an enumerated type should only be assigned valis values that belong to that type. However, compilers may not check that the assignment is valid

## Usage

- Onve defined, enumerated types can be used with any operators that work with scalar values
    ```c++
    switch (result) {
        case OK:
            printf("Loading page.\n");
            break;
        case BAD_REQUEST:
            printf("Invalid request.\n");
            break;
        case NOT_FOUND:
            printf("Cannot find page.\n");
        default:
            break;
    }
    ```
### `typedef`

- There are two ways to `typedef` an enumerated type
- It can be done inline with the definition itself:
    ```c++
    typedef enum {
        OK = 200,
        MOVED_PERMANENTLY = 301,
        BAD_REQUEST = 400,
        FORBIDDEN = 403,
        NOT_FOUND = 404
    } http_status;
    ```
- It can also be done _after_ the initial definintion
    ```c++
    enum http_status {
        OK = 200,
        MOVED_PERMANENTLY = 301,
        BAD_REQUEST = 400,
        FORBIDDEN = 403,
        NOT_FOUND = 404
    };

    typedef enum http_status http_status;
    ```
- Note that, in the orevious examnple, there are two different type names
- The first si `enum` http_status, and the second is simply http_status
- You can use either to create a variable
    ```c++
    enum http status status1 = OK;
    http_status status2 = OK;
    ```

