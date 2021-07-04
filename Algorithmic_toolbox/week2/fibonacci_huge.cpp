#include <iostream>
#include <vector>

long long get_fibonacci_huge(long long n, long long m)
{
    std::vector<long long> F(6*m+1);
    F[0]=0;
    F[1]=1;
    for (long long i = 2; i <= 6*m; i++)
        F[i] = (F[i-1]%m + F[i-2]%m) %m;
    long long i=1;
    while ((F[i]!=0 || F[i+1]!=1) && i<6*m)
        i++;
    return F[n%i];
}

int main()
{
    long long n,m;
    std::cin>>n>>m;
    std::cout<<get_fibonacci_huge(n, m);
    return 0;
}
