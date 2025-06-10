#include "iostream"

class Complex {
private:
	int real;
	int img;
public:
	Complex(int real = 0, int img = 0)
	{
		this->real = real;
		this->img = img;
	}
	Complex operator+(Complex x);
	void getdata();
};

/*
Complex Complex::add(Complex x) {
	Complex temp;
	temp.real = real + x.real;
	temp.img = img + x.img;
	return (temp);
}
*/

Complex Complex::operator+(Complex x) {
	Complex temp;

	// temp.real = real(a) + x.real;
	temp.real = real + x.real;
	// temp.real = real(b) + x.real;
	temp.img = img + x.img;
	return (temp);
}

void Complex::getdata() {
	std:: cout << this->real << std::endl;
	std:: cout << this->img << std::endl;
}

int main()
{
	Complex a(3,7);
	Complex b(5,4);
	// Complex c = a.add(b);
	Complex c = a + b;
	c.getdata();
}