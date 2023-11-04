#include <iostream>
#include <deque>

typedef std::deque< std::pair< std::deque<int>, std::deque<int> > > dequeOfPair;
typedef std::pair< std::deque<int>, std::deque<int> > pears;

void	rec(dequeOfPair &pair, dequeOfPair &tmpPair, pears &stock)
{
	std::deque<int>::iterator it;

	dequeOfPair::iterator pit;
	if (pair.size() == 1)
		return ;
	std::cout << "bef     ";
	for (pit = pair.begin(); pit != pair.end(); pit++)
	{
		std::cout << " [";
		for (it = pit->first.begin(); it != pit->first.end(); it++)
			std::cout << *it << ' ' ;
		std::cout << ',';
		for (it = pit->second.begin(); it != pit->second.end(); it++)
			std::cout << *it << ' ';
		std::cout << "]";
	}
	std::cout << '\n';

	for (pit = pair.begin(); pit != pair.end(); pit++)
	{
		// std::cout << ' ';
			for (it = pit->first.begin(); it != pit->first.end(); it++)
				stock.first.push_back(*it);
			for (it = pit->second.begin(); it != pit->second.end(); it++)
				stock.first.push_back(*it);

			pit++;
			if (pit == pair.end())
				break;
	
			for (it = pit->first.begin(); it != pit->first.end(); it++)
				stock.second.push_back(*it);
			for (it = pit->second.begin(); it != pit->second.end(); it++)
				stock.second.push_back(*it);

		std::cout << stock.first.back() << " " << stock.second.back() << '\n';
			tmpPair.push_back(stock);
			stock.first.clear();
			stock.second.clear();
	}

	std::cout << "after     ";
	for (pit = tmpPair.begin(); pit != tmpPair.end(); pit++)
	{
		std::cout << " [";
		for (it = pit->first.begin(); it != pit->first.end(); it++)
			std::cout << *it << ' ' ;
		std::cout << ',';
		for (it = pit->second.begin(); it != pit->second.end(); it++)
			std::cout << *it << ' ';
		std::cout << "]";
	}
	std::cout << '\n';

	pair = tmpPair;
	tmpPair.clear();
	rec(pair, tmpPair, stock);
}

int main()
{
	dequeOfPair pair, tmpPair;
	pears		stock;

	for (int i = 0; i < 4; i++)
	{
		for (int x = 0; x < 3; x++)
			stock.first.push_back(x + i);
		for (int x = 0; x < 3; x++)
			stock.second.push_back(x + 3 + i);
		pair.push_back(stock);

		stock.first.clear();
		stock.second.clear();
	}

	rec(pair, tmpPair, stock);
	return (0);
}