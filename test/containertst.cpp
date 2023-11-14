#include<iostream>
#include <deque>

int main()
{
	std::deque<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	int x = -1;
	for (std::deque<int>::iterator pit = v.begin(); pit != v.end(); pit++)
	{
	std::cout << " bef " << *pit << '\n';
		if (++x % 2 == 0)
		{
	std::cout << " rm  " << *pit << '\n';
			v.erase(pit);
			// pit = v.begin();
		}
			// if (pit == pend.end())
			// 	break ;
		if (pit == v.end())
			break;
	// std::cout << " in " << x << '\n';
	}

	// std::deque<int>::iterator it = v.begin();
	// std::cout << "bef: " << *it << '\n';
	// v.erase(it);
	// it = v.begin();
	// std::cout << "aft: " << *it << '\n';
}