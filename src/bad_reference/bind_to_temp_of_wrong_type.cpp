struct A
{
};
struct B
{
};
int main()
{
    A& r = B(); // illegal
}
// This will cause a compilation error due to binding a temporary of type B to a non-const lvalue
// reference of type A