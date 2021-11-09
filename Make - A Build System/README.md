# Make - A Build System

- Build systems are what we can use to organize and build programs
- Other build systems
  - cmake
  - cradle

## Header files

- Building programs in C will inevitabily result in many code file, modules, and subsytems It is important to understand and implement best practices when creating and organizing large code bases

## Build systems

- Used to compile with gcc

### Makefiles

- a text file that defines how a project is configured, compiled, installed, and cleaned
```
targets: dependencies
    command1
    command2
    ...
    commandn
```
- `dependencies` - what libraries, files are needed 
- `commands` are shell commands
- useful `target` can be to clean the project
- Makefile name needs to be "Makefile"