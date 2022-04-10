#include <iostream>
#include <vector>

int lcs3(const std::vector<int>& a, const std::vector<int>& b, const std::vector<int>& c)
{
    static int D[200][200][200];
    for (size_t i = 0; i <= a.size(); i++)
    {
        D[i][0][0] = 0;
    }
    for (size_t j = 0; j <= b.size(); j++)
    {
        D[0][j][0] = 0;
    }
    for (size_t k = 0; k <= c.size(); k++)
    {
        D[0][0][k] = 0;
    }
    for (size_t i = 1; i <= a.size(); i++)
    {
        for (size_t j = 1; j <= b.size(); j++)
        {
            for (size_t k = 1; k <= c.size(); k++)
            {
                D[i][j][k]= std::max(std::max(D[i - 1][j][k], D[i][j - 1][k]), D[i][j][k - 1]);
                if (a[i - 1] == b[j - 1] && a[i - 1] == c[k - 1])
                {
                    D[i][j][k] = D[i - 1][j - 1][k - 1] + 1;
                }
            }
        }
    }
    return D[a.size()][b.size()][c.size()];
}

int main()
{
    size_t an, bn, cn;
    std::cin >> an;
    std::vector<int> a(an);
    for (size_t i = 0; i < an; i++)
    {
        std::cin >> a[i];
    }
    std::cin >> bn;
    std::vector<int> b(bn);
    for (size_t i = 0; i < bn; i++)
    {
        std::cin >> b[i];
    }
    std::cin >> cn;
    std::vector<int> c(cn);
    for (size_t i = 0; i < cn; i++)
    {
        std::cin >> c[i];
    };
    std::cout << lcs3(a, b, c);
    return 0;
}
