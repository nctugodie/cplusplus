#include <iostream>
#include <vector>

class foo
{
};

int main()
{
	auto i = 42;        // i is an int
	//auto b; // error
	auto l = 42LL;      // l is an long long
	auto p = new foo(); // p is a foo*

	std::vector<int> v = {0, 1, 2, 3, 4, 5};

	//for (std::vector<int>::const_iterator iterator; iterator !v.end(); ++iterator)
	for (auto iterator = v.begin(); iterator != v.end(); ++iterator)
	{
		std::cout << "emelent " << *iterator << std::endl; 
	}

	return 0;
}

