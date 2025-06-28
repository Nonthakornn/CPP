# Inheritance

- Inheriting from a base class means we don't have to redefine the information from the base class in out derived classes.
- We automatically receive the member function and member variables of the base class through inheritance and then simply add the additional functions or member variables we want.
- This also means that if we ever update or modify the base class (e.g. add new function) all of our derived classes will automativally inherit the changes all of our derived classes will automativally inherit the changes.
- C++ constructs derived classes in phases, starting with the most-base class (at the top of the inheritance tree) and finishing with the most-child class (at the bottom of the inheritance tree). As each class is constructed, the appropriate constructor from that class is called to initialize that part of the class.

## Types of Inheritance

![Types of Inherit](../Asset/inherit.png)

| Access Level | Same Class | Derived Classes | Outside Classes |
|-------------|------------|-----------------|-----------------|
| `private`   | ✅ Yes     | ❌ No           | ❌ No           |
| `protected` | ✅ Yes     | ✅ Yes          | ❌ No           |
| `public`    | ✅ Yes     | ✅ Yes          | ✅ Yes          |

> Constructors can only call constructors from their immediate parent/base class.
> If your base class has virtual functions, your destructor should also be virtual, otherwise undefined behavior will result in certain cases.

## Note

- `double getCost() const` - The const at the end of a function declaration means that this is a const member function
	- it promises not to midify any member variable of the object.

```C++
class Product {
private:
    double price;
    std::string name;

public:
    // ✅ const function - only reads data, doesn't modify
    double getCost() const {
        return price;  // Just reading, not changing
    }
    
    std::string getName() const {
        return name;   // Just reading, not changing  
    }
    
    // ❌ non-const function - modifies data
    void setCost(double newPrice) {
        price = newPrice;  // Changing the object's state
    }
};
```
