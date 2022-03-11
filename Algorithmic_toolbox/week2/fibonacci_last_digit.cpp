#include <iostream>

int get_fibonacci_last_digit(int n)
{
    if (n <= 1) return n;
    int previous = 0;
    int current = 1;
    for (int i = 1; i < n; i++)
    {
        int temp = previous % 10;
        previous = current % 10;
        current = temp + previous;
    }
    return current % 10;
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << get_fibonacci_last_digit(n) << std::endl;
    return 0;
}
