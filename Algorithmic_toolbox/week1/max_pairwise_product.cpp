#include <iostream>
#include <vector>

size_t MaxPairwiseProduct(const std::vector<size_t>& numbers)
{
    size_t max1 = std::max(numbers[0], numbers[1]), max2 = std::min(numbers[0], numbers[1]);
    for (size_t i = 2; i < numbers.size(); i++)
    {
        if (numbers[i] > max1)
        {
            max2 = max1;
            max1 = numbers[i];
        }
        else if (numbers[i] > max2)
        {
            max2 = numbers[i];
        }
    }
    return max1 * max2;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<size_t> numbers(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> numbers[i];
    }
    std::cout << MaxPairwiseProduct(numbers) << std::endl;
    return 0;
}
