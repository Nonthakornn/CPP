#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <typeinfo>

template <typename T>
void iter(T* arr, size_t length, void (*foo)(T &)) {
	if (!arr || !foo)
		return ;
	for (size_t i = 0; i < length; i++)
		foo(arr[i]);
}

void convert_to_ascii(std::string &str)
{
    std::string temp;
    for (size_t i = 0; i < str.size(); i++)
    {
        temp += std::to_string(static_cast<int>(str[i]));
        if (i < str.size() - 1)
            temp += " ";
    }
    str = temp;
}
# endif