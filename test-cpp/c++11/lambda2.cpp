#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
	std::vector<int> v = {0, 1, 2, 3, 4, 5};
	// lambda expression
 	std::for_each(v.begin(), v.end(), [](int i) { std::cout << i << std::endl; } );

	auto f = [](int i) { std::cout << i << std::endl; }; 
	std::for_each(v.begin(), v.end(), f);

	// capture list, [=], [&], [j], [&j], [j, &k], [this]
	int j = 1, k = 2;
	auto f2 = [=](int i) { std::cout << i + j + k << std::endl; };
	std::for_each(v.begin(), v.end(), f2);

	return 0;
}
 				
