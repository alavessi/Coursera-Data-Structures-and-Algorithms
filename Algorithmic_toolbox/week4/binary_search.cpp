#include <iostream>
#include <cassert>
#include <vector>

int bin_search(const std::vector<int>& a, int x)
{
    int left = 0, right = (int)a.size() - 1;
    while(left <= right)
    {
        int middle = (left + right) / 2;
        if (a[middle] == x)
        {
            return middle;
        }
        if (a[middle] < x)
        {
            left = middle + 1;
        }
        if (a[middle] > x)
        {
            right = middle - 1;
        }
    }
    return -1;
}

int linear_search(const std::vector<int>& a, int x)
{
    for (size_t i=0; i<a.size(); i++)
    {
        if (a[i] == x)
        {
            return i;
        }    
    }
    return -1;
}

int main()
{
    int n,k;
    std::cin >> n;
    std::vector<int> a(n);
    for (size_t i=0; i<a.size(); i++)
    {
        std::cin >> a[i];
    }
    std::cin >> k;
    std::vector<int> b(k);
    for (int i=0; i<k; i++)
    {
        std::cin >> b[i];
    }
    for (int i=0; i<k; i++)
    {
        std::cout << bin_search(a, b[i]) << ' ';
    }
    return 0;
}
