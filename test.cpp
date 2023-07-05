
#include <iostream>

class str
{
	public:
		std::string s;
};

int main()
{
	str st;
	st.s = "la";
	st.s = "ja";
	std::cout << st.s << std::endl;
}