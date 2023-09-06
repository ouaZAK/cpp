
// Example: defining the constructor within the class

#include<iostream>
using namespace std;

class dif
{
	private:
		int x;
	public:
		dif()
		{
			std::cout << "dif const\n";
		}
};

class student
{
	private:
		dif h;
	std::string name;
	public:
	student(std::string str)
	{
		std::cout << "std\n";
		name = str;
	}

	student(student const & std)
	{
		name = std.name;
		std::cout << "ooo" << std::endl;
	}

	void display()
	{
		cout<<name << std::endl;
	}
};

int main()
{
	student a("z");
	// student s; //constructor gets called automatically when we create the object of the class
	// student s = student("z");	//call the custom constructor and create a temporary obejct 
	// 							//and then assign it to the e by calling copy constructor if not available
	// student d("");
	// d = s;// assignement operator

	// s.display();
	return 0;
	

}
