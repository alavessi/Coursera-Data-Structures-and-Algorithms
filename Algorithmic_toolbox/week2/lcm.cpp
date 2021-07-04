#include <iostream>

int gcd(int a, int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

long long lcm(long a, long b)
{
    long long d=gcd(a,b);
    return (a/d*b);
}

int main()
{
    int a,b;
    std::cin>>a>>b;
    std::cout<<lcm(a,b)<<std::endl;
}
