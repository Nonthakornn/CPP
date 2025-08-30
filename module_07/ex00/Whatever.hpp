#ifndef WHATEVER_HPP
# define WHATEVER_HPP
# include <iostream>

template <typename T>

void swap(T &a, T &b) {
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <typename J>

J min(J a, J b) {
	return (a < b ? a : b);
}

template <typename K>

K max(K a, K b) {
	return (a > b ? a : b);
}



# endif