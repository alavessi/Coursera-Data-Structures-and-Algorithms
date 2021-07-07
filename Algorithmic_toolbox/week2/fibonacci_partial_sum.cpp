#include <iostream>

int fibonacci_sum_naive(long long n)
{
    if (n =1)
        return n;
    int F[60], S[60];
    F[0]=0;
    F[1]=1;
    S[0]=0;
    S[1]=1;
    for (int i=2; i<60; i++)
    {
        F[i] = F[i-1]%10 + F[i-2]%10;
        S[i] = S[i-1] + F[i]%10;
    }
    return S[n%60]%10;
}
long long get_fibonacci_partial_sum_naive(long long from, long long to)
{
    int S1 = fibonacci_sum_naive(to);
    if (from!=0)
    {
        int S2 = fibonacci_sum_naive(from-1);
        S1 = S1-S2;
    }
    if (S1<0)
        S1 = S1 + 10;
    return S1;
}
int main()
{
    long long from, to;
    std::cin >> from>>to;
    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
}
