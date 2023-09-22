#include <iostream>
/*
template <typename T>
void swap(T &a, T &b)
{
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
const T &func(const T &x)
{
	if (x > 100)
	{
		std::cout << "hohoo" << std::endl;
		return (x);
	}
	else
	{
		std::cout << "weakness " << std::endl;
		return (x);
	}
}

template <typename T>
void	f(T *a, int x, const T &(*fun)(const T &x))
{
	for (int i = 0; i < x; i++)
	{
		a[i] = (*fun)(a[i]);
		std::cout << "this is my power : "<< a[i]<< std::endl;
	}
}

int main()
{
	float x,a,b;
	a = 1.5;
	b = 4.9;
	swap<float>(a, b);
	std::cout << a  << " " << b << std::endl;
	
	int arr[3] = {1,2,300};
	f<int>(arr, 3, func<const int>);
	return (0);
}*/


/*
#################################
when you define member functions for a class template, you need to specify 
the template parameter <T> along with the class name Array to indicate that 
this function is a member of the Array class template and not just a standalone function.
#################################
*/

template <typename T> 
class Array 
{
	private:
		T *ptr;
		int x;
	public:
		Array(T arr[], int x);
		void	print();
};

template <typename T>
Array<T>::Array(T arr[], int x) : x(x)
{
	ptr = new T[3];
	for (int i = 0; i < x; i++)
		ptr[i] = arr[i];
}

template <typename T>
void	Array<T>::print()
{
	for (int i = 0; i < x; i++)
		std::cout << "here : "<< ptr[i] << std::endl;
}

int main()
{
	int arr[3] = {1,2,3};

	Array<int> a(arr, 3);
	a.print();
	int *b = new int();
	std::cout << b[44] << std::endl;
	return (0);
}