#include <iostream>

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
}