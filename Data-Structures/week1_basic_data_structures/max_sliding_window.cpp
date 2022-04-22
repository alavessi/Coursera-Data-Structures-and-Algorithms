#include <iostream>
#include <vector>

void max_sliding_window_naive(const std::vector<int>& A, int w)
{
    int k = A.size() / w;
    int mod = A.size() % w;
    k += mod != 0;
    std::vector<std::vector<int>> Prefix(k), Suffix(k);
    for (int i = 0; i < k - (mod != 0); i++)
    {
        Prefix[i].resize(w);
        Prefix[i][0] = A[i * w];
        Suffix[i].resize(w);
        Suffix[i][w - 1] = A[(i + 1) * w - 1];
    }
    if (mod)
    {
        Prefix[k - 1].resize(mod);
        Prefix[k - 1][0] = A[(k - 1) * w];
        Suffix[k - 1].resize(mod);
        Suffix[k - 1][mod - 1] = A[A.size() - 1];
    }
    for (int i = 0; i < k - (mod != 0); i++)
    {
        for (int j = 1; j < w; j++)
        {
            Prefix[i][j] = std::max(Prefix[i][j - 1], A[i * w + j]);
        }
        for (int j = w - 2; j >=0 ; j--)
        {
            Suffix[i][j] = std::max(Suffix[i][j + 1], A[i * w + j]);
        }
    }
    if (mod)
    {
        for (size_t j = 1; (k - 1) * w + j < A.size(); j++)
        {
            Prefix[k - 1][j] = std::max(Prefix[k - 1][j - 1], A[(k - 1) * w + j]);
        }
        for (int j = (int)A.size() - 2 - (k - 1) * w; j >= 0; j--)
        {
            Suffix[k - 1][j] = std::max(Suffix[k - 1][j + 1], A[(k - 1) * w + j]);
        }
    }
    for (size_t i = 0; i <= A.size () - w; i++)
    {
        std::cout << std::max(Suffix[i / w][i % w], Prefix[i / w + (i % w != 0)][(i + w - 1) % w]) << " ";
    }
}

int main()
{
    size_t n = 0;
    std::cin >> n;
    std::vector<int> A(n);
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> A.at(i);
    }
    int w = 0;
    std::cin >> w;
    max_sliding_window_naive(A, w);
    return 0;
}
