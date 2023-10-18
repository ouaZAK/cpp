#include <iostream>

// class B
// {
// 	private:
// 		int x;
// 	public:
// 		void	func(B &aa)
// 		{
// 			x = aa.x;
// 		}
// };

// class A
// {
// 	private:
// 		int x;
// 	public:
// 		void	func(A &aa)//member functions of a class have access to the private members of other instances of the same class
// 		{
// 			x = aa.x;
// 		}
// 		void	func(B &aa)
// 		{
// 			x = aa.x;
// 		}
// };

// class A {
// public:
//     int data;

//     A(int val) : data(val) {}

//     // Define the assignment operator without returning a reference
//     A operator=(const A& other) {
//         if (this == &other) {
//             return *this; // Handle self-assignment
//         }
//         data = other.data;
//         return *this; // Return a copy of the object (not a reference)
//     }
// };

// int main() {
//    try{

// 	throw(1);
//    }
//    catch(...)
//    {
// 	std::cout <<std::endl;
//    }
//     return 0;
// }

#include <map>
#include <fstream>
#include <iomanip>
int main(int ac, char **av)
{
	std::string av1 = av[1];
	std::ifstream inpF(av1);
	if (!inpF.is_open())
		return (1);
	std::map<std::string, double> map;
	std::string line;
	std::string tmp;
	double		d;

	std::getline(inpF, line);
	while (std::getline(inpF, line))
	{
		tmp = line.substr(0, 10);
		d = std::strtod(line.substr(11, line.size()).c_str(), NULL);
		map.insert(std::make_pair(tmp, d));
	}
	std::map<std::string, double>::iterator it = map.begin();
	for (; it != map.end(); it++)
		std::cout << it->first << " | " << std::fixed << std::setprecision(2) << it->second << std::endl;
	// std::string s1 = "2011-01-01,5";
	// size_t i = s1.find(',', 0);
	// std::cout << i << std::endl;
	// std::cout << s1.substr(0, i) << "\n";
	// std::cout << s1.substr(i + 1, s1.size()) << "\n";
	// std::string s2 = "2010-01-01";
	// if (s1 > s2)
	//    std::cout << "s1 is big\n";
	// else
	//    std::cout << "s1 is small\n";
	return (0);
}
