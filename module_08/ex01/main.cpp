# include "Span.hpp"
# include <iostream>

void subject_test();
void test_with_array();
void test_with_list();
void max_test();

int main()
{
	subject_test();
	test_with_array();
	test_with_list();
	max_test();
}

void subject_test() {

	std::cout << "====== Subject Test ====== " << std::endl;
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void test_with_list() {
	std::cout << "====== Test with list ====== " << std::endl;
	try {
		std::list<int> mylist;
		mylist.push_back(100);
		mylist.push_back(50);
		mylist.push_back(200);
		mylist.push_back(150);

		Span sp = Span(4);
		sp.addNumber(mylist.begin(), mylist.end());
		sp.displayVector();

		// After sorting: 50 100 150 200
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void max_test() {
	std::cout << "====== Maximum Test ====== " << std::endl;
    try {
        const unsigned int N = 10000;
        Span sp(N);

        std::srand(std::time(NULL));
        for (unsigned int i = 0; i < N; ++i) {
            sp.addNumber(std::rand());
        }

        std::cout << "Max test with " << N << " numbers" << std::endl;
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void test_with_array() {
	std::cout << "====== Test with array ====== " << std::endl;
    try {
        int my_array[] = { 1, 10, 2, 20 };
        int n = sizeof(my_array) / sizeof(int);

        Span sp = Span(4);
        sp.addNumber(my_array, my_array + n);
        sp.displayVector();
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}
