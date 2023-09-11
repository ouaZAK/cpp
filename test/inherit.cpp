#include <iostream>


class A
{
	private:
		int age;
	protected:
	public:
		std::string name;
	A(){}
		A(std::string name){std::cout << "A const created"<<std::endl;}
		~A(){std::cout << "A Dest created"<<std::endl;}
		virtual int get() = 0;
		void fun(A &ref)
		{
			std::cout << ref.name;
		}
};

class C : public A
{
	protected:
		int x;
	public:
		C(const std::string &name) : name(name){std::cout << "C const created"<<std::endl;}
		~C(){std::cout << "C Dest created"<<std::endl;}
		int y;
		
		int get()
		{
			return (1);
		}
};
// class D : public A
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
// 		func()
// 		int zz;
// };

// int A::get()
// {
// 	return (age);
// }




int main()
{
	// D s;
	A *me = new C("z");
	me->fun(*me);
	return (0);
}
