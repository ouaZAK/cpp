#include <iostream>

class B
{
	private:
		int x;
	public:
		void	func(B &aa)
		{
			x = aa.x;
		}
};

class A
{
	private:
		int x;
	public:
		void	func(A &aa)//member functions of a class have access to the private members of other instances of the same class
		{
			x = aa.x;
		}
		void	func(B &aa)
		{
			x = aa.x;
		}
};