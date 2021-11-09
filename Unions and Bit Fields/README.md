# Bit Fields

- Bit fields in C allow members of a structure to be packed into a word of memory as part of the definintion of `struct` itself
- Since the entire instuction consists of 32 bits, we could represent this as an `int` 

```c++
// __attribute__((__packet__))
struct thumb_instr { 
    unsigned int           : 3;
    unsigned int opt1      : 2;
    unsigned int opt2      : 7;
    unsigned int reserved1 : 4;
    unsigned int op        : 1;
    unsigned int reserved2 : 15;
} thumb_instr_bit;
```

# Unions

- Only one of the members of a union can be represented in memory at any given time
- Good for resource-limited programs
- Not good for using with pointers

```c++
// building off earlier example
union thumb_instr {
    unsigned int thumb_instr_int;
    thumb_instr_bit bit
}
```