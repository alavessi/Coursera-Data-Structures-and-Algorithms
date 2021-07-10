#include <iostream>
#include <vector>
#include <algorithm>

struct Item
{
    int weight;
    int value;
    friend std::istream& operator>> (std::istream& in, Item& item)
    {
        in >> item.value >> item.weight;
        return in;
    }
};

double get_optimal_value(int n, int capacity, std::vector<Item> items)
{
    double value = 0.0;
    std::sort(items.begin(), items.end(), [] (Item a, Item b) -> bool {return a.value * b.weight > a.weight * b.value;});
    int i=0;
    while (capacity>0 && i<n)
    {
        if (items[i].weight < capacity)
        {
            value += items[i].value;
            capacity -= items[i].weight;
        }
        else
        {
            value += (double)items[i].value * capacity / items[i].weight;
            capacity = 0;
        }
        i++;
    }
    return value;
}

int main()
{
    int n, capacity;
    std::cin >> n >> capacity;
    std::vector<Item> items(n);
    for (int i=0; i<n; i++)
    {
        std::cin >> items[i];
    }
    double optimal_value = get_optimal_value(n, capacity, items);
    std::cout.precision(10);
    std::cout << optimal_value;
    return 0;
}
