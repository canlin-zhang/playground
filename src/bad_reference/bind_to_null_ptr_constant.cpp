int main()
{
    int& r = *static_cast<int*>(0); // UB, but constant-null check should catch
}
