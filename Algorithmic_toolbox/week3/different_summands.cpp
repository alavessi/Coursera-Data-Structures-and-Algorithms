#include <iostream>
#include <vector>

std::vector<int> optimal_summands(int n)
{
    std::vector<int> summands;
    int i = 1;
    while (2*i < n)
    {
        summands.push_back(i);
        n -= i;
        i++;
    }
    if (n)
    {
        summands.push_back(n);
    }
    return summands;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> summands = optimal_summands(n);
    std::cout << summands.size() << std::endl;
    for (unsigned int i=0; i<summands.size(); i++)
    {
        std::cout << summands[i] << " ";
    }
    return 0;
}
