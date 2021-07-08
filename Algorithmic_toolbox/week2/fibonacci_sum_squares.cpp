#include <iostream>

int fibonacci_sum_squares_naive(long long n)
{
    int F[30], S[30];
    F[0]=0;
    F[1]=1;
    S[0]=0;
    S[1]=1;
    for (int i=2; i<30; i++)
    {
        F[i] = F[i-1]%10 + F[i-2]%10;
        S[i] = S[i-1] + ((F[i]%10) * (F[i]%10)) % 10;
    }
    return S[n%30]%10;
}

int main()
{
    long long n;
    std::cin>>n;
    std::cout<<fibonacci_sum_squares_naive(n);
}
