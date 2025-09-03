#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <exception>
# include <stdexcept> 
# include <iterator>
# include <algorithm>

template <typename T>

typename T::iterator easyfind(T& container, const typename T::value_type& value) {

	typename T::iterator it;

	it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::runtime_error("Out of Container");
	return (it);
}


//This one would break if we test it with the string
// The subject said has to find the first occurrence of the second parameter in the first parameter.

/*
typename T::iterator easyfind(T& container, int value) {

	typename T::iterator it;

	it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::runtime_error("Out of Container");
	return (it);
}
*/


# endif