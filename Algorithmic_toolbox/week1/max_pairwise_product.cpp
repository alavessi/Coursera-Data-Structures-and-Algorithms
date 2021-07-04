#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector <long long>& numbers)
{
    long long max_product;
    int i, indmax, indmin, n=numbers.size();
    long long max1=-10000000000000, max2=-10000000000000, min1=100000000000000, min2=1000000000000000;
    for (i=0; i<n; i++)
        if (numbers[i]>max1)
        {
            max1=numbers[i];
            indmax=i;
        }
    for (i=0; i<n; i++)
        if (numbers[i]<min1)
        {
            min1=numbers[i];
            indmin=i;
        }
    for (i=0; i<n; i++)
        if (numbers[i]>max2 && i!=indmax)
            max2=numbers[i];
    for (i=0; i<n; i++)
        if (numbers[i]<min2 && i!=indmin)
            min2=numbers[i];
    max_product=std::max(max1*max2,min1*min2);
    return max_product;
}

int main()
{
    int n;
    std::cin>>n;
    std::vector <long long> numbers(n);
    for (int i=0; i<n; i++)
        std::cin>>numbers[i];
    std::cout<<MaxPairwiseProduct(numbers)<<std::endl;
    return 0;
}
