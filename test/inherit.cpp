#include <iostream>


class A
{
	private:
		int age;
	protected:
		std::string name;
	public:
		A(std::string name){std::cout << "A const created"<<std::endl;}
		~A(){std::cout << "A Dest created"<<std::endl;}
		int get();

};

class C : public A
{
	protected:
		int x;
	public:
		C(){std::cout << "C const created"<<std::endl;}
		~C(){std::cout << "C Dest created"<<std::endl;}
		int y;
};
// class D : public C, public B
// {
// 	protected:
// 		int z;
// 	public:
// 		D(){std::cout << "D const created"<<std::endl;}
// 		~D(){std::cout << "D Dest created"<<std::endl;}
// 		// D(int a, int b, int c)
// 		// {
// 		// 	C::y = a;
// 		// 	C::x = b;
// 		// 	std::cout << B::get() << std::endl;
// 		// }
// 		int zz;
// };

// int A::get()
// {
// 	return (age);
// }


int main()
{
	// D c1;
	C test;
	return (0);
}
