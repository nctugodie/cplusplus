#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	//for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
	for (auto element : v)
	{
		std::cout << element << std::endl;
	}

	int arr[] = {1,2,3,4,5};
	//for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
	for (int& e : arr) 
	{
		std::cout << e << std::endl;
	}

	return 0;
}

