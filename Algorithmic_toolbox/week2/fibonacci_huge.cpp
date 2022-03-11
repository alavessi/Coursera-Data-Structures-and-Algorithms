#include <iostream>
#include <vector>

size_t get_fibonacci_huge(size_t n, size_t m)
{
    std::vector<size_t> F(6 * m + 1);
    F[0] = 0;
    F[1] = 1;
    for (size_t i = 2; i <= 6 * m; i++)
    {
        F[i] = (F[i - 1] % m + F[i - 2] % m) % m;
    }
    size_t i = 1;
    while (i < 6 * m && (F[i] || F[i + 1] != 1))
    {
        i++;
    }
    return F[n % i];
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge(n, m);
    return 0;
}
