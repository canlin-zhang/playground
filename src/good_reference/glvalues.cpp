#include <cassert>
#include <iostream>
#include <memory>
#include <type_traits>
#include <utility>
#include <string>

void print_rvalue(std::string &&s)
{
    std::cout << "Rvalue: " << s << std::endl;
}

void print_lvalue(const std::string &s)
{
    std::cout << "Lvalue: " << s << std::endl;
}

void demo_xvalue()
{
    // This is a lvalue
    // s is not expiring and it is a named object
    std::string s(1000, 'A'); // s is a large string to disable small string optimization
    // Print address of s and s's data container
    std::cout << "Address of s: " << &s << std::endl;
    std::cout << "Address of s's data: " << static_cast<const void *>(s.data()) << std::endl;

    // We move s using an xvalue expression
    auto t = std::move(s);
    std::cout << "std::move is an xvalue expression because it casts s to an rvalue reference, but s is still a lvalue expression, just moved-from." << std::endl;
    std::cout << "Address of t: " << &t << std::endl;
    std::cout << "Address of t's data: " << static_cast<const void *>(t.data()) << std::endl;
    std::cout << "Address of s after move: " << &s << std::endl;
    std::cout << "Address of s's data after move: " << static_cast<const void *>(s.data()) << std::endl;
}

void demo_lvalue()
{
    // This is a lvalue expression
    // 1. It creates a named object "s" on stack (not on heap for this case due to small string optimization)
    std::string s;
    s = "Hello, World!";

    // 2. "s" is an lvalue expression because it has a name and refers to a specific object in memory.
    std::cout << "Address of s: " << &s << std::endl;

    // 3. We can pass "s" to a function that takes an lvalue reference
    print_lvalue(s); // This is an lvalue expression
}

int main()
{
    demo_xvalue();
    demo_lvalue();

    return 0;
}