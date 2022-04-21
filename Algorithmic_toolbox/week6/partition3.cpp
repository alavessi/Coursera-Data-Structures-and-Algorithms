#include <iostream>
#include <vector>

std::vector<std::vector<int>> process(const std::vector<size_t>& A, size_t sum, bool& f, bool inc, size_t& count)
{
    std::vector<std::vector<size_t>> D(A.size() + 1, std::vector<size_t>(sum + 1, 0));
    std::vector<std::vector<int>> From(A.size() + 1, std::vector<int>(sum + 1, 0));
    for (size_t i = 1; i <= A.size(); i++)
    {
        for (size_t j = 1; j <= sum; j++)
        {
            D[i][j] = D[i - 1][j];
            From[i][j] = -1;
            if (j >= A[i - 1] && D[i][j] < D[i - 1][j - A[i - 1]] + A[i - 1])
            {
                D[i][j] = D[i - 1][j - A[i - 1]] + A[i - 1];
                From[i][j] = i - 1;
            }
            if (inc && D[i][j] == sum)
            {
                count++;
            }
        }
    }
    f = D[A.size()][sum] == sum;
    return From;
}

int partition3(std::vector<size_t>& A)
{
    if (A.size() < 3) return 0;
    size_t count = 0, sum = 0;
    bool f1 = false, f2 = false;
    for (int x : A)
    {
        sum += x;
    }
    if (sum % 3) return 0;
    sum /= 3;
    auto From = process(A, sum, f1, true, count);
    for (size_t i = A.size(), j = sum; i && j; i--)
    {
        if (From[i][j] != -1)
        {
            j -= A[i - 1];
            A[i - 1] = 0;
        }
    }
    process(A, sum, f2, false, count);
    return (f1 && f2) || count > 2;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<size_t> v(n);
    for (size_t& x : v)
    {
        std::cin >> x;
    }
    std::cout << partition3(v);
    return 0;
}
