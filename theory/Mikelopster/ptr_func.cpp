#include <iostream>
using namespace std;

int *createArray(int arrsize)
{
	int *arr = new int[arrsize];
	for (int i = 0; i < arrsize; i++)
	{
		arr[i] = i;
	}
	return (arr);

}

int main()
{
	int arrsize = 5;
	int *res = createArray(arrsize);

	for (int i = 0; i < arrsize; i++)
		cout << res[i] << " ";
	delete[] res;
}