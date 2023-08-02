#include <iostream>


class A
{
	private:
		std::string name;
	public:
		A()
		{
			std::cout << "con called\n";
		}
		~A(){std::cout << "des called\n";}
		void	annouce()
		{
			std::cout << name << std::endl;
		}
};

int main()
{
	A z;
	z.annouce();
}