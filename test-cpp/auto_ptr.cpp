#include <memory>
#include <iostream>

int main()
{
    // int* ptr = new int(10);
    // delete ptr;

    std::auto_ptr<int> ptr(new int(10));

    *ptr = 123;
    std::cout << *ptr << std::endl;

    {
        std::auto_ptr<int> ptr2 = ptr;
    }

    *ptr = 456;
    std::cout << *ptr << std::endl;

    return 0;
}