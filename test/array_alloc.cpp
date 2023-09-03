#include <iostream>

int _main()
{
	int **arr;

	arr = new int*[3];
	for (int i = 0; i< 3; i++)
		arr[i] = new int;
	for (int i = 0; i< 3; i++)
		delete []arr[i];
	delete []arr;
	return (0);
}

int main()
{
	_main();
	system("leaks a.out");
}