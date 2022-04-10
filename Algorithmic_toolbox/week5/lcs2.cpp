#include <iostream>
#include <vector>

int lcs2(std::vector<int>& a, std::vector<int>& b)
{
    std::vector<std::vector<int>> D(a.size() + 1, std::vector<int>(b.size() + 1, 0));
    for (size_t i = 1; i <= a.size(); i++)
    {
        for (size_t j = 1; j <= b.size(); j++)
        {
            D[i][j] = std::max(D[i - 1][j], D[i][j - 1]);
            if (a[i - 1] == b[j - 1] && D[i][j] < D[i - 1][j - 1] + 1)
            {
                D[i][j] = D[i - 1][j - 1] + 1;
            }
        }
    }
    return D[a.size()][b.size()];
}

int main()
{
    size_t n, m;
    std::cin >> n;
    std::vector<int> a(n);
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    std::cin >> m;
    std::vector<int> b(m);
    for (size_t i = 0; i < m; i++)
    {
        std::cin >> b[i];
    }
    std::cout << lcs2(a, b);
    return 0;
}
