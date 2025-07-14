#include <iostream>

using namespace std;

int *fun() {
	int *p = new int[5];
	for (int i =0; i < 5; i++) {
		p[i] = 5 * i;
	}
	cout << "Address of P: " << p << endl;
	return (p);
}

int main() {
	int *q = fun();
	cout << "Address of q: " << q << endl;
	delete q;
}