#include <iostream>
#include <vector>

int get_change(int m)
{
    std::vector<int> a(m + 1);
    a[0] = 0;
    for (int i = 1; i <= m; i++)
    {
        a[i] = a[i - 1] + 1;
        if (i >= 3)
        {
            a[i] = std::min(a[i], a[i - 3] + 1);
        }
        if (i >= 4)
        {
            a[i] = std::min(a[i], a[i - 4] + 1);
        }
    }
    return a[m];
}

int main()
{
    int m;
    std::cin >> m;
    std::cout << get_change(m);
    return 0;
}
