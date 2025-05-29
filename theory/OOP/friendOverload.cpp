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
	friend Complex operator+(Complex x, Complex y);
	void getdata();
};

Complex operator+(Complex x, Complex y) {
	Complex temp;

	temp.real = x.real + y.real;
	temp.img = x.img + y.img;
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