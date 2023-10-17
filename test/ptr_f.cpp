#include <iostream>

class Harl
{
	private :
	public :
		void	lala(void);
		void complane(std::string lvl);
};

void	Harl::lala(void)
{
	std::cout << "lala"<<std::endl;
}

int main()
{
	// std::string str = "ha";
	// std::string *ptr;
	// std::string &ref = *ptr; //A reference must always be initialized with an object, not a pointer
	// std::string* &ref = ptr; // This creates a reference to the pointer 'ptr'

	Harl test;
	// void (Harl::*ex)() = &Harl::lala;
	// (test.*ex)();
	int y = 7;
	int const &x = y;
	y = 8;
	x = 9;//cant do this because x in const but we can change value of variable refered to
//#########
//or different way to declare ptr to fun 
 void (Harl::*f)();
	f = &Harl::lala;
	(test.*f)();
}
