#include <iostream>

template <typename T1, typename T2>
auto compose(T1 t1, T2 t2) -> decltype(t1 + t2)
{
	return t1+t2;
}

int main()
{
	int i = 33;
	decltype(i) j = i*2; // j's type is int

	auto v = compose(2, 3.14); // v's type is double
	std::cout << "v=" << v << std::endl;

	auto f = [](int a, int b) -> int { return a*b; };
	decltype(f) f2 = f; // the type of a lambda function is unique and unnamed
	std::cout << "f2=" << f2(3, 3) << std::endl;

	return 0;
}

