# ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <algorithm>
# include <vector>
# include <stdexcept>
# include <limits>

class Span {
private:
	unsigned int		_N;
	std::vector<int>	_vec;

public:
	Span();
	Span(unsigned int N);
	Span(const Span& rhs);
	Span& operator=(const Span& rhs);
	~Span();

	void addNumber(int num);
	int shortestSpan();
	int longestSpan();
	void displayVector();

};

#endif