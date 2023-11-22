#include <iostream>

class A 
{
	public:
		int z;
		virtual ~A(){};
		operator float()
		{
			z = 77;
			return (static_cast<float>(z));
		}
};
class B:public A {public:int x;};
class C:public A {public:int y;};

int main()
{
	B b;
	C c;
	A *a = dynamic_cast<A *>(&b);
	A *ac = dynamic_cast<A *>(&c);
	B *bb = dynamic_cast<B *>(ac);
	B *btoc = dynamic_cast<B *>(&c);
	if (!bb)
		std::cout << "failed\n";
	else
	{
		bb->x = 2;
	std::cout << bb->x << std::endl;
	}
	if (!a)
		std::cout << "failed\n";
	else
		a->z=9;
	std::cout << a->z << std::endl;
	try
	{
		C &d = dynamic_cast<C &>(*a);
		d.y = 8;
	std::cout << d.y << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// int p;
	// // p[0] = 10;
	// // int &m = p[0];
	// float x;
	// x = reinterpret_cast<float>(p);
	// std::cout << "here ->>>" << x << std::endl;

	// A a1;
	// float h =a1;
	// std::cout << h<< std::endl; 

	// int k = -1;
	// void *s = &k;
	// int *pt = static_cast<int *>(s);
	// int i = *pt; 
	// std::cout << i ;
	// int x;
	// float y= 1.1F;
	// std::cout << y << std::endl;
	// x = static_cast<int>(y);
	// std::cout << x << std::endl;
	// std::cout << "------------------\n";

	// char c;
	// int z = 49;

	// c = static_cast<char>(z);
	// std::cout << c << std::endl;
	// std::cout << "------------------\n";


	// char s = '3';
	// int i;

	// i = static_cast<int>(s);
	// std::cout << i << std::endl;
	// std::cout << "------------------\n";
	
	// int j = 7;
	// void *k = static_cast<void*>(&j);
	// int *o = static_cast<int*>(k);
	
	// std::cout << *o<< std::endl;
	// std::cout << "------------------\n";
	
	// char v;
	// // int *p = static_cast<int*>(&v);//error static protect from doing this nonesense
	// // derived der;
	// // base *ptr1 = static_cast<base *>(&der);
	// std::cout << "cant do" << std::endl;
	// std::cout << "------------------\n";
	return (0);
}



// int main()
// {
// 	const int x = 5;
// 	int &y = const_cast<int&>(x);
// 	y = 10;

// 	const int a = 5;
//  	const int &y = a;
// 	std::cout << y << std::endl;
// 	std::cout << x << std::endl;
// }