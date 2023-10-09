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
#include <iostream>

class A {
public:
    int data;

    A(int val) : data(val) {}

    // Define the assignment operator without returning a reference
    A operator=(const A& other) {
        if (this == &other) {
            return *this; // Handle self-assignment
        }
        data = other.data;
        return *this; // Return a copy of the object (not a reference)
    }
};

int main() {
    A obj1(1);
    A obj2(2);
    A obj3(3);

    // Chain assignments
    obj1 = obj2 = obj3; // This won't work as expected

    std::cout << "obj1.data: " << obj1.data << std::endl;
    std::cout << "obj2.data: " << obj2.data << std::endl;
    std::cout << "obj3.data: " << obj3.data << std::endl;

    return 0;
}
