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

## Constructor

- Constructor perform initialization of any member variables
- Constructor may perform other setup function such as
  - error checking
  - Memory allocation
  - Initialization of state
- After the constrcutor finished execting we say that the object has been "constructed" and the object should now be in a conssitent, unable state.
- Constructor allow to call other function, including other member function

### Naming Constructors

- Constructor have specific rules for how they must be named:
  - Constructor must have the same name as the class (with the same capitalization)
  - Constructors have no return type (not even `void`)
- Constructors should now be const.

```CPP
Person(int age) {
    if (age < 0 || age > 150) {
        throw std::invalid_argument("Wrong age");
    }
    this->age = age;
}
```

### Member initializer list format

- You cannot initialize static member variables in a constructor's initializer list because static members don't belong to any specific instance of the class.
- Static members exist before any objects are created, and they continue to exist even if no objects exist. They need to be initialized only once, not each time an object is constructed.
- Static variables with local scope: These are also automatically initialized to zero.

```CPP
class Account {
private:
	static int _nbAccounts;
};

Account::Account(int initial_deposit)
    : _nbAccounts(0)  // Error! Can't initialize static member in initializer list
{
    // ...
}
```

```CPP
Foo(int x, int y) : m_x { x }, m_y { y }
{
}

Foo(int x, int y) :
    m_x { x },
    m_y { y }
{
}

Foo(int x, int y)
    : m_x { x }
    , m_y { y }
{
}
```

> Best practice is to put the colon on the lone after the constructor name,
> Indent your member initializer list to make it easier to see the function names.

```CPP
Foo(int x, int y)
    : m_x { x }
    , m_y { y }
{
}
```

### Type of Constructor

1. Default Constructor
2. Non-parameterized Constructor (Also known as Default Constructor)

```CPP
class Rectangle {

private:
	int length;
	int breath;
public:
	Rectangle() {
		length = 0;
		breath = 0;
	}
}

//Default constructor
Rectangle r()
```

3. Parameterized Constructor

```CPP
class Rectangle {

private:
	int length;
	int breath;
public:
	Rectangle(int l, int b) {
		length = l;
		breath = b;
	}
}
//Parameterize constructor
Rectangle r(12, 10);
```

```CPP
class Rectangle {

private:
	int length;
	int breath;
public:
	Rectangle(int l = 0, int b = 0) {
		length = l;
		breath = b;
	}
	/*
	You dont need this if you assign to 0
	Rectangle() {
		length = 0;
		breath = 0;
	}
	*/
}
//Parameterize constructor
Rectangle r(12, 10)
```

4. Copy Constructor

```CPP
class Rectangle {

private:
	int length;
	int breath;
public:
	Rectangle(Rectangle &rect) {
		length = rect.lenght;
		breath = rect.breath;
	}
}
Rectangle r();
Rectangle r(10,5);
//Copy Constructor
Rectangle r2(r);
```

### Encapsulation