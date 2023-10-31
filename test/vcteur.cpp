#include <iostream>
#include <vector>

std::ostream &operator<<(std::ostream &out, const std::vector<int> &vec)
{
	std::vector<int>::const_iterator cit;
	for (cit = vec.begin(); cit != vec.end(); cit++)
		out << *cit << " ";
	return (out);
}

int main(int ac, char **av)
{
	std::vector< std::vector<int> > a;
	std::vector<int> b;
	a.push_back(b);

	std::cout << a.at(0) << '\n';
	return (0);
}
