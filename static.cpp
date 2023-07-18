#include <iostream>
class A
{
	public :
		int y;
		static const int x; 
		A operator++()
		{
			++y;
			return (*this);
		}
		A operator++(int)
		{
			A t;
			t.y = y; // y = 0;
			y++; // y = 1;
			return (t);
		}
};

const int A::x = 9;

int main()
{
	A a,b;
	a.y = 0;
	b = a++;
	std::cout << b.y << " a= " << a.y;
	return (0);
}