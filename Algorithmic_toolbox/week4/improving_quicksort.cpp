#include <iostream>
#include <vector>
//#include <algorithm>

int partition2(std::vector<int> &a, int l, int r)
{
    int x = a[l];
    int j = l;
    for (int i = l + 1; i <= r; i++)
    {
        if (a[i] <= x)
        {
            j++;
            std::swap(a[i], a[j]);
        }
    }
    std::swap(a[l], a[j]);
    return j;
}

void randomized_quick_sort(std::vector<int> &a, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int k = l + rand() % (r - l + 1);
    std::swap(a[l], a[k]);
    int m = partition2(a, l, r);
    randomized_quick_sort(a, l, m - 1);
    randomized_quick_sort(a, m + 1, r);
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (size_t i=0; i<a.size(); i++)
    {
        std::cin >> a[i];
    }
    randomized_quick_sort(a, 0, n-1);
    //std::sort(a.begin(), a.end());
    for (size_t i=0; i<a.size(); i++)
    {
        std::cout << a[i] << " ";
    }
    return 0;
}
