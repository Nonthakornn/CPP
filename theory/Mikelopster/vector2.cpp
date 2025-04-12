#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> vec = {1, 2, 3};
	int *ptr = vec.data();

	ptr[0] = 10;
	cout << *ptr;
}
