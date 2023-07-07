#include <iostream>

class test
{
	private :
		std::string str;

	public :
		// void	get_it(std::string &str);
		test(std::string const &s) : str(s)
		{
			std::cout << str << " is alive"<< std::endl;
		}
		~test()
		{
			std::cout << "died"<< std::endl;
		}
		std::string &ref()
		{
			// this->str += " oua";
			return (this->str);
		}
		std::string *ptr()
		{
			// this->str += " ouaaaa";
			return &(this->str);
		}
};

void	get_it(std::string &str)
{
	str += " lala";
}

void	get_ptr(std::string *str)
{
	*str += " hmmmm";
}

int main()
{
	test str("zak");
	std::string s= "ha";

	get_it(s);
	std::cout << s << std::endl;
	get_ptr(&s);
	std::cout << s <<std::endl;

	std::cout <<"ptr = "<< *(str.ptr()) << std::endl;
	std::cout <<"ref = "<< str.ref() << std::endl;

	str.ref() = "zzz";
	std::cout << str.ref() << std::endl;
	return (0);
}