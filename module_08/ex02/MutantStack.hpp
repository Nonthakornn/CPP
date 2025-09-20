#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

# include <iostream>
# include <vector>
# include <stack>
# include <deque>
# include <list>
# include <vector>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
	typedef typename std::stack<T, Container>::container_type::iterator iterator;

	MutantStack() {};

	MutantStack(const MutantStack& rhs): std::stack<T, Container>(rhs) {};

	MutantStack& operator=(const MutantStack& rhs) {
		if (this != &rhs)
			std::stack<T, Container>::operator=(rhs);
		return (*this);
	};
	~MutantStack() {};

	iterator begin() {
		return (this->c.begin());
	}

	iterator end() {
		return (this->c.end());
	}
};

# endif