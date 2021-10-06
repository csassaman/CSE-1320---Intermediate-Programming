# Structs and Typedefs

## Aggregate Data Types

- Aggregate data types are designed to store multiple valies
- We have been using arrays, which is an instance of an aggregate datatype
- Aggregate date types are not necessarily restricted to multiple valies of a single type
- C structs permit the storage of multiple data types within one entity

## Structs

- Structs are creates in C to represent complex data. If we wanted a struct to represent a user in a generic database, the declaration would look like this:

```c++
#define MAX_STR_LEN 128
struct user {
    int id;
    char username[MAX_STR_LEN];
    char password[MAX_STR_LEN];
    char email[MAX_STR_LEN];
}
```

- Each individual date type declared within the `struct` is referred to as a __member__
- The previous example was a `struct` with 4 members
- A `struct` in C can have almost any data member with a few exceptions
  - A member cannot be a function
  - A member cannot have type `void`
  - The `struct` cannot have a member with the same name type as the `struct`
- Note that the name of the `struct` given in the precious declaration is not the name of the individual variable
- To create an instance of the previously declared `struct`, the declaration would be 
    ```c++
    struct user user_var;
    ```
- Here, the type is `struct user` and the identifier is `user_var`
- The declaration of the `struct` can be combinded with the declaration of variables
    ```c++
    #define MAX_STR_LEN 128
    struct user {
        int id;
        char username[MAX_STR_LEN];
        char password[MAX_STR_LEN];
        char email[MAX_STR_LEN];
    } user1, user2;
    ```

## Accessing Members

- The member of a struct can be accessed uising __dot notation__
  - `user_var.username'

## Arrays of Structs

- Since a `struct` is a data type, it can be created as an array
- Consider the declaration: `struct creature dragons[5];`
- This creates an array of `struct` with size 5 to store creature data
- Accessing individual elements is similar to any other array:
    ```c++
    dragons[0]; // first member
    dragons[1]; // second member
    ```
- Similarly, accessing members of each element is as easy and using the dot notation on th element that was acessed
    ```c++
    dragons[0].name;
    ```
- Since struct can be initialized with an assignment, so can an array of `streuct`
    ```c++
    struct creature dragons[5] = {
        { "Brimsnythe" },
        {},
        {},
        {},
        {}
    }
    ```

## Struct Pointers

- A pointer to `struct` can be created just as a pointer to any other data type
    ```c++
    struct creature *creature_ptr;
    ```
- When working with a pointer to `struct`, the syntax to access the members changes slightly
    ```c++
    creature_ptr->name;
    creature+ptr->hp;
    ```
- Pointers to `struct` allow a loophole to the previous restriction on member data types
- A `struct` may not have a data member which is of its own type
- however, it may have a pointer to that type
- 