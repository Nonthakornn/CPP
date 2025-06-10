# Overload

Function overloading allows us to crate multiple functions with the same name.

```C++
double add(double x, double y)
{
    return x + y;
}
```

```C++
int add(int x, int y) // integer version
{
    return x + y;
}

double add(double x, double y) // floating point version
{
    return x + y;
}

int main()
{
    return 0;
}
```

- The above program will compile. Although you might expect these functions to result in a naming conflict, that is not the case here. Because the parameter types of these functions differ, the compiler is able to differentiate these functions, and will treat them as separate functions that just happen to share a name.

> Function overloading provides a great way to reduce the complexity of your program by reducing the number of function names you need to remember. It can and should be used liberally.

## Limitations on operator overloading

- Almost any existing operator in C++ can be overloaded. The exceptions are: conditional (?:), sizeof, scope (::), member selector (.), pointer member selector (.*), typeid, and the casting operators.
- You can only overload the operators that exist. You can not create new operators or rename existing operators. For example, you could not create an operator** to do exponents.
- At least one of the operands in an overloaded operator must be a user-defined type. This means you could overload `operator+(int, Mystring)`, but not `operator+(int, double)`.

>In basic mathematics, exponentiation is resolved before basic arithmetic, so 4 + 3 ^ 2 resolves as 4 + (3 ^ 2) => 4 + 9 => 13.
>However, in C++, the arithmetic operators have higher precedence than operator^, so 4 + 3 ^ 2 resolves as (4 + 3) ^ 2 => 7 ^ 2 => 49.