# Object Oriented Programming

- Object is a piece of memory to store values.

## Struct

```C++
#include <iostream>
struct Date
{
    int day{};
    int month{};
    int year{};
};

void printDate(const Date& date)
{
    std::cout << date.day << '/' << date.month << '/' << date.year;
}

int main()
{
    Date date{ 4, 10, 21 }; // initialize using aggregate initialization
    printDate(date);        // can pass entire struct to function

    return 0;
}
```

```C
void printDate(const struct Date* date)
{
    printf("%d/%d/%d", date->day, date->month, date->year);
}

int main()
{
    struct Date date = {4, 10, 21};
    printDate(&date);  // Notice we pass the address explicitly with &
    return 0;
}
```

## Class

### Public and Private Members
- Class is a program-defined data type, it must be defined before it can be used. Classes are defined similarly to structs, except we use the class keyword instead of struct.
- Functions that belong to a class type are called member functions.
- Access level summary

| Access level | Access specifier | Member access | Derived class access | Public access |
|--------------|------------------|--------------|----------------------|---------------|
| Public       | public:          | yes          | yes                  | yes           |
| Protected    | protected:       | yes          | yes                  | no            |
| Private      | private:         | yes          | no                   | no            |

- A private member is a member of a class that can only be accessed by other members of the class.
- A member function can directly access private members, Because access levels are per-class, not per-object, a member function can also directly access the private members of ANY other object of the same class type that is in scope.

### Access Function 

- Access functions come in two flavors: getters and setters.
  - Getters (also sometimes called accessors) are public member functions that return the value of a private member variable. 
  - Setters (also sometimes called mutators) are public member functions that set the value of a private member variable.

> A member function returning a reference should return a reference of the same type as the data member being returned, to avoid unnecessary conversions.

### Encapsulation