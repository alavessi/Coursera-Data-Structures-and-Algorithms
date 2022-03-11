#include <iostream>

size_t fibonacci_sum_naive(size_t n)
{
    if (n <= 1) return n;
    size_t F[60] = {0, 1}, S[60] = {0, 1};
    for (size_t i = 2; i < 60; i++)
    {
        F[i] = F[i - 1] % 10 + F[i - 2] % 10;
        S[i] = S[i - 1] + F[i] % 10;
    }
    return S[n % 60] % 10;
}

int main()
{
    size_t n;
    std::cin >> n;
    std::cout << fibonacci_sum_naive(n) << std::endl;
    return 0;
}
