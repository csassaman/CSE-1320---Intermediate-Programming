# unix

## unix commands

- `cat` -  concatinate file, prints to stdout
- `grep` 

## streams

- 0 - stdin: standard input
- 1 - stdout: standard output
- 2 - stderr: standard error

## redirection

input and output can be redirected ising `n>` and `<`

- `n>` - n is the file descriptor, 1 by default
- `2>&1` - redirects stderr to stdout
- `&>` - shorthanbd for `2>&1`

### example 

```
gcc problem1.c -Wall 2>&1 | grep error
```

1. `gcc proble,1.c -Wall` compiles problem1.c with all warnings
2. `2>&1` redirects standard error messages to standard out
3. `|` pipes to grep
4. `grep error` searches message for lines with the error key 

## End of Line Conversions

```
cat file.txt
    | tr '\r' '\n'
    | tr -s '\n'
    > newfile.txt
```

- `tr` means translate
- `-s` squeeze
- can also downlad _dos2unix_ or _unix2dos_ to use in terminal to convert file from unix format to dos(windows) format or visa versa
