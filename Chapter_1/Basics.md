# Chapter 1

## 1.1 Statements and the structure of a program

- **Statement** - A statement is an instruction in a computer program that tells the computer to perform action.
  - Most statements in C++ end in a semicolon. If you see a line that ends in a semicolon , its probably a statement.
- **Function** - A funciton is a collection of statements that execute sequentially.

## 1.2 Introduction to objects and variables

- A single piece of data is called a `value`.
- Random Access Memory - The main memory in a computer is called Random Access Memory (oftern called RAM). When we run a program, the operating system loads the program into RAM. Any data that is hardcoded into the program itself (e.g. text such as "Hello") is loaded at this point.
- An **OBJECT** represent a region of storage(typically RAM or CPU register) that can hold a value.
  - An object is used to store a value in memory. A variable is an object that has a name(identifier).

### Data types

- A data type (more commonly just called type) determines what kind of value (eg. number, text, etc...) the object will store.
- In C++, the type of an object must be known at compile-time, and that type can not be changed without recompiling the program.

```C++
//Correct and it is the best practice
int a;
int b;
int a, b;

//Wrong
int a, int b;
int a, double b;
```

- What is data?
  - Information that can be moved, process or stored by a computer.
- What is a value?
  - A value is a letter, number, text or instance of some other useful concept that can be represent as data.
- What is obect?
  - It is a region of storage (usually memory) that can store a value.
- What is a variable?
  - Obect that has a name.
- What is a data type used for?
  - Determines what kind of value the object will store.

> Warning! - Assignment (=) is used to assign a value to a variable. Equality (==) is used to test whether two operands are equal in value.

### Intialization

```C++
int a;         // default-initialization (no initializer)

// Traditional initialization forms:
int b = 5;     // copy-initialization (initial value after equals sign)
int c ( 6 );   // direct-initialization (initial value in parenthesis)

// Modern initialization forms (preferred):
int d { 7 };   // direct-list-initialization (initial value in braces)
int e {};      // value-initialization (empty braces)
```
> You may see the above forms written with different spacing (e.g. int b=5; int c(6);, int d{7};, int e{};). Whether you use extra spaces for readability or not is a matter of personal preference.

## 1.3 iostream: cout, cin, and endl

- The io part of iostream stands for input/output.
- `cout` - stands for "character output" (It can print text, float and number)
- `endl` - stands for "end line"

```c++
#include <iostream>

int main()
{
	int x{5};

	std::cout << x << endl;
	std::cout << "Hello World";
}
```

> Best Practice: Output a newline whenever a line of output is complete.

- `std::cout` is buffered - The output is typically not send to the console immediately. Instead, the request output "get in line" and is stored in a region of memory set aside to coolect such request (called a **buffer**). Periodically, the buffer is flushed, **meaning all the data collected in the buffer is tranderred to its destination** (in our case, the console).
  - This means that if your program crashes (e.g. for debugging purposes) before the buffer is flushed, any output still waiting in the buffer will not be displayed.

> The opposite of buffered output is unbuffered output (In C `write()`). With unbuffered output, each individual output request is sent directly to the output device

### **`std::endl` vs `\n`**

- Using `std::endl` is oftern inefficient, as it actually does two jobs:
  - It outputs a newline (moving the cursor to the next line of the console)
  - It flushes the buffer (which is slow).
- If we output multiple lines of text ending with `std::endl`, we will get multiple flushes, which is slow and probably unnedcessary.
- When outputting text to the console, we typically don’t need to explicitly flush the buffer ourselves. C++’s output system is designed to self-flush periodically, and it’s both simpler and more efficient to let it flush itself.

```C++
#include <iostream> // for std::cout

int main()
{
    int x{ 5 };
    std::cout << "x is equal to: " << x << '\n'; // single quoted (by itself) (conventional)
    std::cout << "Yep." << "\n";                 // double quoted (by itself) (unconventional but okay)
    std::cout << "And that's all, folks!\n";     // between double quotes in existing text (conventional)
    return 0;
}
```

> Prefer `\n` over `std:endl` when outputting text to the console

### `std::cin`

- `cin` - stands for "character input"
- `cin` is buffered  

```C++
#include <iostream>  // for std::cout and std::cin

int main()
{
    std::cout << "Enter a number: "; // ask user for a number

    int x{};       // define variable x to hold user input (and value-initialize it)
    std::cin >> x; // get number from keyboard and store it in variable x

    std::cout << "You entered " << x << '\n';
    return 0;
}
```

- If the user types 5a and enter, 5a\n will be added to the buffer. 5 will be extracted, converted to an integer, and assigned to variable x. a\n will be left in the input buffer for the next extraction.

- If the user types ‘b’ and enter, b\n would be added to the buffer. Because b is not a valid integer, no characters can be extracted, so this is an extraction failure. Variable x would be set to 0, and future extractions will fail until the input stream is cleared.

> Each line of input data in the input buffer is terminated by `'\n` character.

