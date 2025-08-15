#include <iostream>
#include <cassert>
#include <memory>
#include <type_traits>

int main()
{
    int x = 42;
    int &r = x; // r is a reference to x

    // Print values to show they refer to the same object
    std::cout << "Value of x: " << x << std::endl;
    std::cout << "Value of r: " << r << std::endl;

    // Print addresses to show they refer to the same object
    std::cout << "Address of x: " << &x << std::endl;
    std::cout << "Address of r: " << &r << std::endl;

    int y = 100;
    r = y; // r is now assigned the value of y, but it's a write-through
    std::cout << "Value of x after assignment: " << x << std::endl;
    std::cout << "Value of r after assignment: " << r << std::endl;

    assert(&r == &x); // r still refers to the same object as x
    assert(&r != &y); // r does not refer to y, it still refers to x

    // Print addresses again to confirm they are still the same
    std::cout << "Address of x after assignment: " << &x << std::endl;
    std::cout << "Address of r after assignment: " << &r << std::endl;
    std::cout << "Address of y: " << &y << std::endl;

    // r = nullptr; // This is not valid, as r is a reference and cannot be null

    // Increment (arithmetic) does not change the object r refers to
    r++; // Incrementing the value of x through r
    std::cout << "Value of x after increment: " << x << std::endl;
    std::cout << "Value of r after increment: " << r << std::endl;
    assert(&r == &x); // r still refers to the same object as x
    std::cout << "Address of x after increment: " << &x << std::endl;
    std::cout << "Address of r after increment: " << &r << std::endl;

    // (&r)++; // This is not valid, as r is a reference and cannot be incremented like a pointer

    return 0;
}