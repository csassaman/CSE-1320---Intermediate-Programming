# Make - A Build System

- Build systems are what we can use to organize and build programs
- Other build systems
  - cmake
  - cradle

## Header files

- Building programs in C will inevitabily result in many code file, modules, and subsytems. It is important to understand and implement best practices when creating and organizing large code bases

## Build systems

- There are a number of built dydtems to help organize C projects such as:
  - Make
  - Ninja
  - CMake
  - Bazel
- The organization of the build is defined in what is called a __Makefile__

## Makefiles

```
targets: dependencies
    command1
    command2
    ...
    commandn
```
- A __Makefile__ is a text file that defines how a project is configured, compiled, installed, and cleaned

- The `targets` specify a named rule
- `dependencies` - what libraries, files are needed 
- `commands` are shell commands
- Multiple targets can be added depending on the requirements (testing, debugging, release)
    ```
    project:
        gcc project.c -o project
    test:
        gcc tests.c project.c -o test
    ```
- It is common to add a `clean` target to remove unnecssary output
    ```
    project:
        gcc project.c -o project
    
    clean: 
        rm -f project
    ```

- Makefile name needs to be "Makefile"

### Variables

- It is possible to inlude variables in a Makefile. This is useful when organizing a very large project with different groups
- [Example](Makefile)

### Automatic Variables

- Depending on your configuration, the target and prerequisite names might be variable. In that case, it is impossible to write them out directly
- Automatic variables are provided for each rule, based on the target and prerequisits
- _Some frequently used automatic variables:_
  - `$@` - Returns the file name of the target of the rule
  - `$^` - Returns the name of all prerequisites
  - `$?` - Returns the name of all prerequisites that are newer than the target
- [A full list can be found here](https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html)