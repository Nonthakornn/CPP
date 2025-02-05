#include <iostream>


using namespace std;

int main() 
{
	int arr[] = {1, 2, 3, 4, 5};
	int *ptr = arr;

	int length = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < length; i++)
		cout << *(ptr + i) << " ";

}

/*
int i = 5;
printf("%d", ++i);  // Prints 6
printf("%d", i);    // Prints 6

int j = 5;
printf("%d", j++);  // Prints 5
printf("%d", j);    // Prints 6
*/
