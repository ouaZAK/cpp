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
		void set(std::string str)
		{
			name = str;
		}

};
std::ostream &operator<< (std::ostream &out, const A &n)
{
	out << n.set("zzz");
	return (out);
}

int main()
{
	A z;
	z.annouce();
}