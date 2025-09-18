# ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <algorithm>
# include <vector>
# include <list>
# include <stdexcept>
# include <limits>
# include <cstdlib>   // rand()
# include <ctime>     // time()

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
	template <typename InputIterator>
	void addNumber(InputIterator first, InputIterator last) {
        if (std::distance(first, last) + _vec.size() > _N) {
            throw std::length_error("Container does not have enough space!");
        }
		// void insert (iterator position, InputIterator first, InputIterator last);
        _vec.insert(_vec.end(), first, last);
    }
	int shortestSpan();
	int longestSpan();
	void displayVector();
};

#endif