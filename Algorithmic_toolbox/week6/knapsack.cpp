#include <iostream>
#include <vector>

int optimal_weight(int W, const std::vector<int>& w)
{
    std::vector<std::vector<int>> D(w.size() + 1, std::vector<int>(W + 1, 0));
    for (size_t i = 1; i <= w.size(); i++)
    {
        for (int j = 1; j <= W; j++)
        {
            D[i][j] = D[i - 1][j];
            if (j >= w[i - 1])
            {
                D[i][j] = std::max(D[i][j], D[i - 1][j - w[i - 1]] + w[i - 1]);
            }
        }
    }
    return D[w.size()][W];
}

int main()
{
    int n, W;
    std::cin >> W >> n;
    std::vector<int> w(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> w[i];
    }
    std::cout << optimal_weight(W, w);
    return 0;
}
