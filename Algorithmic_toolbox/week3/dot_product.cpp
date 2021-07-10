#include <iostream>
#include <algorithm>
#include <vector>

long long max_dot_product(std::vector<int> a, std::vector<int> b)
{
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    long long result = 0;
    for (int i=0; i<a.size(); i++)
    {
        result += ((long long)a[i]) * b[i];
    }
    return result;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (size_t i=0; i<n; i++)
    {
        std::cin >> a[i];
    }
    for (size_t i=0; i<n; i++)
    {
        std::cin >> b[i];
    }
    std::cout << max_dot_product(a, b);
    return 0;
}
