#include <iostream>

using namespace std;

void helloFunction(int a)
{
	cout << "Hello Number: " << a << '\n';
}

int main()
{
	int number = 10;
	int arr[5] = {1, 2, 3, 4, 5};
	int *ptr = &number;
	int *ptr2 = arr;

	// cout << &number << "\n";
	// cout << ptr << "\n";
	// cout << *ptr << "\n";

	cout << arr << '\n'; //0x16fa7ae50
	cout << &arr[1] << '\n'; //0x16fa7ae50
	cout << ptr2 << '\n'; //0x16fa7ae50
	cout << *(ptr2 + 1) << '\n';

	void (*functionPtr)(int) = helloFunction;
	functionPtr(1);

}