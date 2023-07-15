#include <iostream>
/*
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

*/

#include <fstream>
#include <string.h>
int	main(int ac, char **av)
{
	if (ac == 4)
	{
		std::string		name = av[1];
		
		std::ifstream	ifs(name);
		if (ifs.fail())
		{
			std::cout << "Can't open " << name << std::endl;
			return (1);
		}
		
		std::ofstream	ofs(name + ".replace");
		if (ofs.fail())
		{
			std::cout << "Can't open " << name + ".replace" << std::endl;
			return (1);
		}
		
		std::string		in;
		std::string		str;

		while(std::getline(ifs, in))
		{
			while (in.find(av[2]) != std::string::npos && strcmp(av[2], av[3]))
				in = in.substr(0, in.find(av[2])) + av[3] + in.substr(in.find(av[2]) + strlen(av[2]), in.length());
			str += in;
			if (!ifs.eof())
				str += "\n";
		}
		ofs << str;
		ifs.close();
		ofs.close();
	}
	else
		std::cout << "Sed: <filename> s1:string to replace s2:to replace with" << std::endl;
}