#include <iostream>

// class B
// {
// 	private:
// 		int x;
// 	public:
// 		void	func(B &aa)
// 		{
// 			x = aa.x;
// 		}
// };

// class A
// {
// 	private:
// 		int x;
// 	public:
// 		void	func(A &aa)//member functions of a class have access to the private members of other instances of the same class
// 		{
// 			x = aa.x;
// 		}
// 		void	func(B &aa)
// 		{
// 			x = aa.x;
// 		}
// };

// class A {
// public:
//     int data;

//     A(int val) : data(val) {}

//     // Define the assignment operator without returning a reference
//     A operator=(const A& other) {
//         if (this == &other) {
//             return *this; // Handle self-assignment
//         }
//         data = other.data;
//         return *this; // Return a copy of the object (not a reference)
//     }
// };

int main() {
   try{

	throw(1);
   }
   catch(...)
   {
	std::cout <<std::endl;
   }
    return 0;
}
