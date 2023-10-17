#include <iostream>
#include <map>

int main()
{
	std::multimap<int, std::string> a;
	a.insert(std::make_pair(1, "a"));
	a.insert(std::make_pair(1, "f"));
	std::cout << a.size() << std::endl;
	a.insert(std::make_pair(3, "x"));
	a.insert(std::make_pair(3, "z"));
	a.insert(std::make_pair(2, "b"));
	a.insert(std::make_pair(2, "d"));
	a.insert(std::make_pair(3, "y"));
	a.insert(std::make_pair(1, "D"));
	std::map<int, std::string>::iterator it = a.begin();
	for (; it != a.end(); it++)
		std::cout << it->first << " " << it->second << std::endl;
	// it = a.find(1);
	// if (it != a.end())
	// 	std::cout << it->first << " " << it->second << std::endl;
	// a.erase(3);
	// it = a.find(3);
	// if (it != a.end())
	// 	std::cout << it->first << " " << it->second << std::endl;
	return (0);
}