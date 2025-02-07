#include <iostream>

using namespace std;

void square(int n) { cout << n * n << " "; }
void doubleNumber(int n) { cout << n * 2 << " "; }

void processArray(int *arr, int size, void (*callback)(int))
{
	for (int i = 0; i < size; i++)
		callback(arr[i]);
	cout << endl;
}

int main()
{
	int myArr[] = {1, 2, 3, 4, 5};
	int size = sizeof(myArr) / sizeof(myArr[0]);

	cout << "Square Element\n";
	processArray(myArr, size, square);

	cout << "Double Element\n";
	processArray(myArr, size, doubleNumber);
}
