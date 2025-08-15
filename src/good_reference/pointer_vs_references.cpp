#include <cassert>
#include <iostream>
#include <memory>
#include <type_traits>
#include <utility>

void pointer_demo()
{
    std::cout << "Demonstrating pointers in C++" << std::endl << std::endl;

    int x = 42;
    int* p = &x; // p is a pointer to x

    // Print their memory addresses to show they aren't the same object
    std::cout << "Address of x: " << &x << std::endl;
    std::cout << "Address of p: " << &p << std::endl;
    assert(
        reinterpret_cast<void*>(std::addressof(p)) !=
        reinterpret_cast<void*>(std::addressof(x))); // p is not the same as x, it's a pointer to x

    // However, show that p points to the address of x
    std::cout << "Value of p (address of x): " << p << std::endl;
    std::cout << "Address of x: " << &x << std::endl;

    // P is re-assignable
    int y = 100;
    p = &y; // p now points to y
    std::cout << "Value of p (address stored) after assignment: " << p << std::endl;
    std::cout << "Address of y: " << &y << std::endl;
    std::cout << "Address of x: " << &x << std::endl;
    assert(p != &x); // p now points to y, not x
    assert(p == &y); // p points to y

    // P can be null
    p = nullptr; // p is now a null pointer
    std::cout << "Value of p after setting to nullptr: " << p << std::endl;
    assert(p == nullptr); // p is null

    // P can be incrementd to change the address it points to (pointer arithmetic)
    int arr[] = {1, 2, 3, 4, 5};
    p = arr; // p now points to the first element of arr
    std::cout << "Value of p (address of arr[0]): " << p << std::endl;
    std::cout << "Value of *p (value at arr[0]): " << *p << std::endl;
    p++; // Incrementing p to point to the next element
    std::cout << "Value of p after increment (address of arr[1]): " << p << std::endl;
    std::cout << "Value of *p after increment (value at arr[1]): " << *p << std::endl;
    assert(p == &arr[1]); // p now points to the second element of arr

    std::cout << "Demonstration of pointers complete." << std::endl << std::endl;
}

void reference_demo()
{
    std::cout << "Demonstrating references in C++" << std::endl << std::endl;

    int x = 42;
    int& r = x; // r is a reference to x

    // Print addresses to show they refer to the same object
    std::cout << "Address of x: " << &x << std::endl;
    std::cout << "Address of r: " << &r << std::endl;
    assert(&x == &r); // r refers to the same object as x

    // Reference is not re-assignable
    int y = 100;
    // This assignment writes through the reference
    r = y; // r is now assigned the value of y, but it's a write-through
    std::cout << "Value of x after assignment: " << x << std::endl;
    std::cout << "Value of r after assignment: " << r << std::endl;
    std::cout << "Address of x after assignment: " << &x << std::endl;
    std::cout << "Address of r after assignment: " << &r << std::endl;
    assert(&r == &x); // r still refers to the same object as x
    assert(&r != &y); // r does not refer to y, it still refers to x

    // Reference cannot be null - at least not in well-defined C++ code
    // r = nullptr; // This is not valid, as r is a reference and cannot
    // be null
    // However, this is undefined behavior
    int* p = nullptr;
    int& p_ref = *p; // This is undefined behavior, dereferencing a null pointer
    // std::cout << "Value of p_ref (undefined behavior): " << p_ref << std::endl;

    // Increment (arithmetic) does not change the object r refers to
    // It writes through the reference instead
    r++; // Incrementing the value of x through r
    std::cout << "Value of x after increment: " << x << std::endl;
    std::cout << "Value of r after increment: " << r << std::endl;
    assert(&r == &x); // r still refers to the same object as x
    std::cout << "Address of x after increment: " << &x << std::endl;
    std::cout << "Address of r after increment: " << &r << std::endl;

    std::cout << "Demonstration of references complete." << std::endl << std::endl;
}

int main()
{

    pointer_demo();
    reference_demo();

    return 0;
}