#include <iostream>
#include <vector>

template <typename T>
void easyfind(const T &t, const int &i)
{
	typename T::const_iterator it;//typename is obligatory to precise that iterator is a type not a variable of T

	it = std::find(t.begin(), t.end(), i);//If std::find does not find the element in the container, it returns an iterator that is equal to the end()
	if (it == t.end())
		throw (std::exception());
}

int main()
{
	std::vector<int>v(2);
	std::vector<int>w;

	w.push_back(2);
	w.push_back(3);
	w.push_back(4);

	v.resize(w.size());

	std::copy(w.begin(), w.end(), v.begin());

	for (int i = 0; i < w.size(); i++)
		std::cout << v.at(i) << std::endl;

	std::vector<int>::reverse_iterator it = v.rbegin();
	for (; it != v.rend(); it++)
		std::cout << "it: " << *it << std::endl;

	return (0);
}