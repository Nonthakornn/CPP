# Type Cast

## 1. Static Cast

- Used for sensible, well-defined conversions between related types
- Converts between numeric types (like `int` to `float`)
  - Pointers up and down a class hierarchy.
  - It's like converting ounces to grams. They are different units for measuring weight, and there's a clear, logical way to convert between them.

```C++
#include <iostream>

int main()
{
	float myFloat = 1.999;
	int myInt = static_cast<int>(myFloat);

	std::cout << "MyFloat: " << myFloat << std::endl;
	std::cout << "MyInt: " << myInt<< std::endl;
}
```

## 2. Dynamic Cast

- Used exclusively with pointers and reference to objects in a class hierarchy.
- It designed for sage Down Casting.
  - Down Casting is a pointer of a base class to pointer of derived class.
- It check at run time to see if the conversion is actually valid. If you try to cast a base class pointer to derived class pointer, but the object is not actually of the derived type `dynamic_cast` will return `nullptr` or thorw an exception (for reference)
  - This prevent you from accidentally using a pointer tha points to the wrong type of object.
- You can't use dynamic_cast to change a Base into a Derived. You can only use it to "uncover" or "reveal" that a Base pointer is already pointing to a Derived object.

```C++
#include <iostream>

class Animal {
public:
	virtual ~Animal() {}
};

class Dog: public Animal {};


int main()
{
	{
		Base * b = new Base();
		Derived *d = new Derived();

		// Base->Derived
		// This one is invalid
		if (dynamic_cast<Derived*>(b)) {
			std::cout << "Treating 'b' like Derived" << std::endl;
		}
	}

	{
		Animal *myAnimal = new Dog();
		Dog *myDog = dynamic_cast<Dog*>(myAnimal);

		if (myDog)
			std::cout << "Success Casting" << std::endl;
	}
}
```

## 3. Const Cast

- This is used to add or remove the `const` qualifier from a variable.
- The `const` keyword makes a variable read-only. `const_cast` is the only C++ cast that can modify this
- It lets you change a const variable so you can write to it. This is generally considered dangerous and should be avoided unless you have a specific reason like interfacing with an old library.

```C++
#include <iostream>

int main()
{
	const int myConst = 100;
	int* nonConst = const_cast<int*>(&myConst);
	*nonConst = 200; // Changes the value of myConst (use with extreme caution!)
}
```

## 4. Reinterpret Cast

- This is the most powerful and dangerous cast. It can convert between any pointer type or from a pointer to an integer, regardless of whether the types are related.
- It reinterprets the binary pattern of one type as another. It does not do any checking or conversion. It assumes you know exactly what you are doing.
- It's like taking the raw binary data for a JPEG image file and telling the computer to open it as a text document.

```C++
int myInt = 65;
int* intPtr = &myInt;
// Cast the integer pointer to a character pointer
char* charPtr = reinterpret_cast<char*>(intPtr);
// Now charPtr points to the raw memory of myInt.
// On many systems, this would print 'A', the ASCII value for 65.
```
