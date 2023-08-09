#include <iostream>
#include <sstream>
#include <string>

int main() {
    int x;

    std::cin >> x;  //read "123iu" from input
    std::cout << x; //print 123 but stream buffer still have "iu"
    std::cin >> x; //when call cin again it read the previous buffer wich is "iu"
    std::cout << x; //and print "1230" 0 because converting characters to int is not working
    // std::string str = "-1.20";
    
    // std::stringstream ss(str);  // Create a stringstream initialized with the string
    // int intValue;
    
    // ss >> intValue;  // Extract the integer from the stringstream
    
    // if (!ss.fail() && ss.eof()) {
        // std::cout << "Converted integer: " << intValue << std::endl;
    // } else {
    //     std::cout << "Conversion failed." << intValue << std::endl;
    // }
    
    return 0;
}

/*
// C++ program to demonstrate the
// use of a stringstream to
// convert string to int
#include <iostream>
#include <sstream>
using namespace std;

// Driver code
int main()
{
	string s = "12345";

	// object from the class stringstream
	int x = 777;
	stringstream geek;

	// inserting string s in geek stream
	geek << x;
string str;
	// The object has the value 12345
	// and stream it to the integer x
	geek >> str;

	// Now the variable x holds the
	// value 12345
	cout << "Value of x + 1 : " << str + " ha";

	return 0;
}


*/