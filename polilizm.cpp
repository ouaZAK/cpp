#include <iostream>
//polymorphisme
// class Animal
// {
// 	protected:
// 		std::string type;
// 	public:
// 		virtual void	annouce(const std::string &str)
// 		{
// 			std::cout << "hello " << str << std::endl;
// 		}
// };

// class Dog : public Animal
// {
// 	public:
// 		virtual void	annouce(const std::string &str)
// 		{
// 			std::cout << "bye dog " << str << std::endl;
// 		}
// };

//###############################

// abstract
class AAnimal //A for abstract Animal
{
	protected:
		std::string type;
	public:
		virtual void	annouce(const std::string &str) = 0; //need to be virtual because derived Dog has the same function, and does not have an implementation in the base class
};

class Dog : public AAnimal
{
	public:
		virtual void	annouce(const std::string &str) // the derived class must have the function and its implementation
		{
			std::cout << "bye dog " << str << std::endl;
		}
};

//###############################
//interface      //have only have pure methode
// class IAnimal
// {
// 	// protected:          // interface cant have an attribute
// 	// 	std::string type;
// 	public:
// 		virtual void	annouce(const std::string &str) = 0;
// 		virtual void	bark(const std::string &str) = 0; 
// };

// class Dog : public IAnimal
// {
// 	public:
// 		virtual void	annouce(const std::string &str) // the derived class must have the function and its implementation
// 		{
// 			std::cout << "bye si " << str << std::endl;
// 		}
// 		virtual void	bark(const std::string &str) // the derived class must have the function and its implementation
// 		{
// 			std::cout << "lala " << str << std::endl;
// 		}
// };


int main()
{
	//poly
	// Animal *a = new Animal;
	// Dog *b = new Dog;
	// Animal *c = new Dog;

	// a->annouce("ayaa");
	// b->annouce("ayaa");
	// c->annouce("ayaa");

//##################
	//abstract
	// AAnimal *a = new AAnimal; //cant do that because abstract class cant have an instance 
	AAnimal *a = new Dog;
	AAnimal *v;
	Dog *b = new Dog;

	a->annouce("ayaa");
	b->annouce("ayaa");

//###############
	//interface
	// IAnimal *a = new IAnimal; //cant do that either
	// IAnimal *c = new Dog;
	// Dog *a = new Dog;

	// c->bark("j");
	// a->annouce("z");
	// a->bark("jaja");
}