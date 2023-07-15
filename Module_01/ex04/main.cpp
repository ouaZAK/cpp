#include <iostream>
#include <string.h>
#include <fstream>

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "enter 3 argument : \"<filename>\"  \"s1\"  \"s2\"" << std::endl;
		return (0);
	}

	std::string		loc = av[1];
	std::ifstream	inpF(loc);
	if (inpF.fail())
	{
		std::cout << "fail to open"<< std::endl;
		return (2);
	}
	std::ofstream	outF(loc + ".replace");
	if (outF.fail())
	{
		std::cout << "fail to open"<< std::endl;
		return (2);
	}

	std::string strFull;
	size_t lenLoc = 0;
	size_t pos = 0;
	int n = 0;

	while (1)
	{
		std::getline(inpF, loc);
		lenLoc += loc.length() + 1;
		strFull += (loc + "\n");
		pos = strFull.find(av[2], strFull.length() - lenLoc);
		while (pos < lenLoc)
		{
			if (pos != strFull.npos)
			{
				n = strFull.find(av[2], strFull.length() - lenLoc);
				strFull.erase(n,strlen(av[2]));
				strFull.insert(n, av[3]);
			}
			pos = strFull.find(av[2], strFull.length()) - lenLoc;
		}
		if (inpF.eof())
			break ;
	}
	outF << strFull;
	outF.close();
	inpF.close();
	return (0);
}