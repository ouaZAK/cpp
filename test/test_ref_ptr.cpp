#include <iostream>

// class test
// {
// 	private :
// 		std::string str;

// 	public :
// 		// void	get_it(std::string &str);
// 		test(std::string const &s) : str(s)
// 		{
// 			std::cout << str << " is alive"<< std::endl;
// 		}
// 		~test()
// 		{
// 			std::cout << "died"<< std::endl;
// 		}
// 		std::string &ref()
// 		{
// 			// this->str += " oua";
// 			return (this->str);
// 		}
// 		std::string *ptr()
// 		{
// 			// this->str += " ouaaaa";
// 			return &(this->str);
// 		}
// };

// void	get_it(std::string &str)
// {
// 	str += " lala";
// }
class A
{
	public:
		int	&get_ptr(int x) const
		{
			x++;
			return x;
		}
		int	&get_ptr(int x, int &y)
		{
			return get_ptr(x);
		}
};

int	&get_ptr(int x)
{
	x++;
	return x;
}
int	&get_ptr(int x, int &y)
{
	return get_ptr(x);
}
#include <vector>
int main()
{
	int a = 5;
	int b = 2;
	int const &c = a * b;
	int const &d = 8;
	int f = 8;
	int &g = f;
	int x = get_ptr(a, g);
	std::cout << x << std::endl;
	std::vector<int> v = {0,1,2,3};
	int& i = v[2];
	v.resize(20);  
	i = 5;
	std::cout << i << std::endl;

	A a1;
	std::cout << a1.get_ptr(i) << std::endl;
	const A &a2 = a1;
	std::cout << a2.get_ptr(i) << std::endl;
	std::cout << a2.get_ptr(b,a) << std::endl;

	// test str("zak");
	// std::string s= "ha";

	// get_it(s);
	// std::cout << s << std::endl;
	// get_ptr(&s);
	// std::cout << s <<std::endl;

	// std::cout <<"ptr = "<< *(str.ptr()) << std::endl;
	// std::cout <<"ref = "<< str.ref() << std::endl;

	// str.ref() = "zzz";
	// std::cout << str.ref() << std::endl;
	return (0);
}


// #include <sstream>
// #include <strstream>

// class A
// {
// 	public:
// 	int x;
// 	void	di()
// 	{
// 		x = 0;
// 	}
// 		void	dis()
// 		{
// 			// int x = 10;
// 			std::cout << x << "hahah" << std::endl;
// 		}
// 		// void	dis1()
// 		// {
// 		// 	std::cout << x << std::endl;
// 		// }
// };


// int main()
// {
// 	A *ptr = NULL;
// 	ptr->dis();
// 	// A a(0),b(2),c(3),d(3);

// 	// a += b += c += d;
// 	// std::cout << a << b  << "\n";
// 	// std::stringstream s;

// 	// std::string c = "   1.5k";
// 	// std::string f;
// 	// s << c ;
// 	// s >> f;

// 	// std::cout << f << std::endl;
// }