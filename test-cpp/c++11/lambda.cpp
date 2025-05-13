#include <vector>
#include <iostream>
#include <algorithm>

void function(int i)
{
	std::cout << i << std::endl;
}

class functor
{
public:
	void operator()(int i) { std::cout << i << std::endl; }
};

int main()
{
	std::vector<int> v = {0, 1, 2, 3, 4, 5};
	// pass object
	std::for_each(v.begin(), v.end(), functor());
	// pass function pointer
	std::for_each(v.begin(), v.end(), function);

	return 0;
}
