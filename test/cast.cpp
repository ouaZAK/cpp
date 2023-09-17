#include <iostream>

int main()
{
	int x;
	float y= 2.3f;

	x = static_cast<int>(y);
	std::cout << x << std::endl;
	std::cout << "------------------\n";

	char c;
	int z = 49;

	c = static_cast<char>(z);
	std::cout << c << std::endl;
	std::cout << "------------------\n";


	char s = '3';
	int i;

	i = static_cast<int>(s);
	std::cout << i << std::endl;
	std::cout << "------------------\n";
	
	int j = 7;
	void *k = static_cast<void*>(&j);
	int *o = static_cast<int*>(k);
	
	std::cout << *o<< std::endl;
	std::cout << "------------------\n";
	
	char v;
	// int *p = static_cast<int*>(&v);//error static protect from doing this nonesense
	// derived der;
	// base *ptr1 = static_cast<base *>(&der);
	std::cout << "cant do" << std::endl;
	std::cout << "------------------\n";
	return (0);
}

