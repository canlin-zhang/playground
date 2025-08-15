#include <iostream>
#include <string>
#include <utility>

void demo_rvalue()
{
    // ----- prvalue (pure rvalue) -----
    // Prvalue is a temporary object that is not stored in a variable, so it doesn't have a stable
    // address. You can't compile this line, uncomment to see the error: "error: taking address of
    // rvalue" std::cout << "[prvalue] &std::string(1000, 'R'): "
    //           << static_cast<const void *>(&std::string(1000, 'R')) << '\n';

    // Note that a non-const lvalue reference cannot bind to a prvalue.
    // Uncommenting the next line will cause a compilation error:
    // cannot bind non-const lvalue reference of type ‘std::string&’ {aka
    // ‘std::__cxx11::basic_string<char>&’} to an rvalue of type ‘std::string’ {aka
    // ‘std::__cxx11::basic_string<char>’} std::string &s2 = std::string(1000, 'A');

    // We need to bind it to a const lvalue reference expression to see the address of a prvalue.
    const std::string s = std::string(1000, 'A');

    // Print address of s and s's data container
    std::cout << "Address of s (i.e., the prvalue): " << &s << std::endl;
    std::cout << "Address of s's data: " << static_cast<const void*>(s.data()) << std::endl;

    // We move s using an xvalue expression
    std::string t = std::move(s);
    std::cout << "std::move is an xvalue expression because it casts s to an rvalue reference."
              << std::endl;
    std::cout << "Address of t: " << &t << std::endl;
    std::cout << "Address of t's data: " << static_cast<const void*>(t.data()) << std::endl;
    std::cout << "Address of s after move: " << &s << std::endl;
    std::cout << "Address of s's data after move: " << static_cast<const void*>(s.data())
              << std::endl;
}

int main()
{
    demo_rvalue();
}
