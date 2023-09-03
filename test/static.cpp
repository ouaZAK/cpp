#include <iostream>
class A
{
	private:
		int y;
	public :
		A();
		
		A(int x)
		{
			std::cout << "custom const called\n";
			y = x;
		}
		A(const A &b)
		{
			std::cout << "copy const called\n";
			y = b.y;
		}
		~A()
		{
			std::cout << "des called\n";
		}
		int geter()
		{
			return (y);
		}
		void print()
		{
			std::cout << " called\n";
		}
		// static const int x; 
		// A operator++()
		// {
		// 	++y;
		// 	return (*this);
		// }
		// A operator++(int)
		// {
		// 	A t;
		// 	t.y = y; // y = 0;
		// 	y++; // y = 1;
		// 	return (t);
		// }
};

A::A()
{
	std::cout << "const called\n";
	y = 5;
}
// const int A::x = 9;
int main()
{

	A b(0);
	A a(b);
	a.print();
	int x = a.geter();
	// b = a++;
	std::cout  << x << std::endl;
	return (0);
}