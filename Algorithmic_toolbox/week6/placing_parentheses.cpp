#include <iostream>
#include <cassert>
#include <string>
#include <vector>

const long long INF = 1000000000;

long long eval(long long a, long long b, char op)
{
    switch (op)
    {
    case '*':
        return a * b;
        break;
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    default:
        assert(0);
    }
}

long long minimum(const std::vector<std::vector<long long>>& M, const std::vector<std::vector<long long>>& m, size_t i, size_t j, const std::vector<char>& operators)
{
    long long min = INF;
    for (size_t k = i; k < j; k++)
    {
        long long a = eval(M[i][k], M[k + 1][j], operators[k]);
        long long b = eval(M[i][k], m[k + 1][j], operators[k]);
        long long c = eval(m[i][k], M[k + 1][j], operators[k]);
        long long d = eval(m[i][k], m[k + 1][j], operators[k]);
        min = std::min(std::min(std::min(std::min(min, a), b), c), d);
    }
    return min;
}

long long maximum(const std::vector<std::vector<long long>>& M, const std::vector<std::vector<long long>>& m, size_t i, size_t j, const std::vector<char>& operators)
{
    long long max = -1 * INF;
    for (size_t k = i; k < j; k++)
    {
        long long a = eval(M[i][k], M[k + 1][j], operators[k]);
        long long b = eval(M[i][k], m[k + 1][j], operators[k]);
        long long c = eval(m[i][k], M[k + 1][j], operators[k]);
        long long d = eval(m[i][k], m[k + 1][j], operators[k]);
        max = std::max(std::max(std::max(std::max(max, a), b), c), d);
    }
    return max;
}

long long get_maximum_value(const std::string& exp)
{
    const size_t n = exp.size() / 2 + 1;
    std::vector<std::vector<long long>> M(n + 1, std::vector<long long>(n + 1, 0)), m(n + 1, std::vector<long long>(n + 1, 0));
    std::vector<int> d;
    std::vector<char> operators;
    d.push_back(0);
    operators.push_back('0');
    for (size_t i = 0; i < exp.size(); i++)
    {
        if (i % 2)
        {
            operators.push_back(exp[i]);
        }
        else
        {
            d.push_back(exp[i] - 48);
        }
    }
    for (size_t i = 1; i <= n; i++)
    {
        m[i][i] = d[i];
        M[i][i] = d[i];
    }
    for (size_t s = 1; s < n; s++)
    {
        for (size_t i = 1; i <= n - s; i++)
        {
            size_t j = i + s;
            m[i][j] = minimum(M, m, i, j, operators);
            M[i][j] = maximum(M, m, i, j, operators);
        }
    }
    return M[1][n];
}

int main()
{
    std::string s;
    std::cin >> s;
    std::cout << get_maximum_value(s);
    return 0;
}
