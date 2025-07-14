# Exception

- In C++, we use try-catch blocks(and throw statements) to handle runtime errors gracefully rather than letting the program crash.
- Without exception handling: When an error occurs (like dividing by zero, accessing invalid memory, or opening a non-existent file), the program typically crash or produces undefined behaviour.
- With exception handling: We can catch these errors, handle them appropriately ansd allow your program to continue running or exit gracefully.

## Error

1. Syntax Error - Complier
2. Logical Error - Debugger
3. Runtime Error - bad input, problem with Resources


## Throw

- We can throw any type of data including class
  
```C++
class MyException: public exception {

}
```

