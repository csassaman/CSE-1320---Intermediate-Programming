# File I/O

- File input and oputput is not part of the C language itself. The concept of files are implemented by the Operating System
- C library functions use system calls to facilitate processing data with files
- C puts input in a buffer until the user presses `<Enter>`
- Output is kept in the buffer until one of a number of events occurs (called flushing)
    1. A newline character is places in the buffer
    2. The buffer becomes full
    3. The sustem prepares for input
    4. The program terminates
    5. All input is read and new input must be read

## Files in C

- Stream of bytes
- _It is up to the programmer_ to put any sort of rules and organization on how the date in each files is represented (e.g. CSV, JSON, etc.)
- C __always__ opens three files when a program is run
    1. `stdin`
    2. `stdout`
    3. `stderr`
- Each of these files have type `FILE *`
  - `FILE` refers to a structure in C that stores information about the file

## Opening a File

- Files are opened in C through the use of `fopen`, which is included in `stdio.h`
    ```c++
    FILE *f = fopen("data.txt", "r");
    ```
  - `"r"` - read only. Does not override the file
  - `"w"` - Open a new file for writing. Will override if file exists
  - `"a"` - Open a file for appending (can be used if file already exists). Puts file pointer at end of file
  - `"r+"` - Open an existing file for update (reading and writing)
  - `"w+"` - Open a new file for update
  - `"a+"` - Open a new (or existing) file for reading and appending
  - `"_b"` - Binary flag. Can be added to reading, writing, or appending flags

## Closing a File

```c++
fclose(f);
```

- ___Alwauys close files after working on them___
- Closing a file after reading/writing operations are complete is important to sever the reference between your program and the file itself
- It also provides a way to check for any errors that may have occurred with the file
- If file doesn't exist, trying to close the file will cause a segmentation fault, crashing the program
- Best practice to add a safe guard

```c++
if (f != NULL) {
    fclose(f);
}
```

## Reading and Writing Lines

- `fgets()` can be used to read from and `FILE *`, not just `stdin`
- [read_csv.c](read_csv.c)

## Reading and Writing Blocks of Data

```c++
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream );

size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
```

- Used when working with binary data
- Mostly use `fwrite()`: Will write binary data directly to file