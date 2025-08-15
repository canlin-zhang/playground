#include <iostream>

struct Foo
{
    int*& bar;
};

int* p = nullptr;
Foo foo{p};

int main()
{
    {
        int x = 42;
        foo.bar = &x;
    }

    int y = *foo.bar;

    std::cout << "Value of y: " << y << std::endl; // Should print 42

    return 0;
}
