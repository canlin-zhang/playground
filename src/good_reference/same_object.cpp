#include <cassert>
#include <memory>
#include <iostream>
#include <type_traits>

int main()
{

    int x = 42;
    int &r = x; // r is a reference to x

    std::cout << "Address of x: " << &x << std::endl;
    std::cout << "Address of r: " << &r << std::endl;

    assert(&x == &r); // r refers to the same object as x

    return 0;
}