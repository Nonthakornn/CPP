#include <iostream>
#include <vector>

using namespace std;

int main()
{
	//init vector
	vector<int> vec;
	vector<int> vec2 = {1,2,3,4,5};
	vector<int> vec3(5,10);

	vec.push_back(10); // [] -> [10]
	vec.push_back(20); // [10] -> [10, 20]
	vec.push_back(30); // [10, 20] -> [10, 20, 30]

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << "\n";
}


