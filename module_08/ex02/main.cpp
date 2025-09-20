#include "MutantStack.hpp"

void compare_with_list();
void mutantStack_with_vector();

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "mstack top: " << mstack.top() << std::endl;
	mstack.pop();

	std::cout << "mstack size after pop: "<< mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	std::cout << "Final MutantStack: " << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
	std::stack<int> s(mstack);
	std::cout << std::endl;
	compare_with_list();
	// mutantStack_with_vector();

	return 0;
}

void compare_with_list() {
	
	std::cout << "====== Compare with list ======" << std::endl;

	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << "list back: " << lst.back() << std::endl;
	lst.pop_back();

	std::cout << "list size after pop: " << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::list<int>::iterator lit = lst.begin();
	std::list<int>::iterator lite = lst.end();

	++lit;
	--lit;

	std::cout << "Final std::list iteration: " << std::endl;
	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}
}

void mutantStack_with_vector() {

	std::cout << "====== Mutant Stack with Vector ======" << std::endl;

	MutantStack<int, std::vector<int> > mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "mstack top: " << mstack.top() << std::endl;
	mstack.pop();

	std::cout << "mstack size after pop: "<< mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int, std::vector<int> >::iterator it = mstack.begin();
	MutantStack<int, std::vector<int> >::iterator ite = mstack.end();

	++it;
	--it;

	std::cout << "Final MutantStack: " << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
	std::stack<int, std::vector<int> > s(mstack);
	std::cout << std::endl;
}