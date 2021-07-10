#include <iostream>
#include <algorithm>
#include <vector>

bool get_majority_element(std::vector<int> &a, int n)
{
    std::sort(a.begin(),a.end());
    int k = 1;
    int x = a[0];
    for (int i=1; i<n; i++)
    {
        if (a[i]==x)
        {
            k++;
        }
        else
        {
            if (k > n/2)
            {
                return 1;
            }
            k = 1;
            x = a[i];
        }
    }
    return k > n/2;
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
    std::cout << get_majority_element(a,a.size());
    return 0;
}
