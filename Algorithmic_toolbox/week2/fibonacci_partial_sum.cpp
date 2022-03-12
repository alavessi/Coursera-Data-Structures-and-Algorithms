#include <iostream>

int fibonacci_sum_naive(long long n)
{
    if (n <= 1) return n;
    int F[60] = {0, 1}, S[60] = {0, 1};
    for (int i = 2; i < 60; i++)
    {
        F[i] = F[i - 1] % 10 + F[i - 2] % 10;
        S[i] = (S[i - 1] + F[i]) % 10;
    }
    return S[n % 60] % 10;
}

long long get_fibonacci_partial_sum_naive(long long from, long long to)
{
    long long S1 = fibonacci_sum_naive(to);
    if (from)
    {
        S1 -= fibonacci_sum_naive(from - 1);
        S1 += 10 * (S1 < 0);
    }
    return S1;
}

int main()
{
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    return 0;
}
