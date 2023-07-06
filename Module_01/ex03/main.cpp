#include <iostream>

class test
{
	private :
		std::string str;

	public :
		std::string &get_it(std::string &str);
		// test(std::string s)
		// {
		// 	std::cout << s << " is alive"<< std::endl;
		// }
		// ~test()
		// {
		// 	std::cout << "died"<< std::endl;
		// }
};

std::string &get_it(std::string &str)
{
	str += " lala";
	return (str);
}

int main()
{
	test str;
	std::string s = "haha ";

	str.get_it(s);
	std::cout << s << std::endl;
	return (0);
}