#include <iostream>
#include <vector>

std::vector<int> optimal_sequence(int n)
{
    std::vector<int> a(n + 1), pointer(n + 1);
    a[1] = 0;
    pointer[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        a[i] = a[i - 1] + 1;
        pointer[i] = 1;
        if (i % 2 == 0 && a[i / 2] + 1 < a[i])
        {
            a[i] = a[i / 2] + 1;
            pointer[i] = 2;
        }
        if (i % 3 == 0 && a[i / 3] + 1 < a[i])
        {
            a[i] = a[i / 3] + 1;
            pointer[i] = 3;
        }
    }
    std::vector<int> sequence(a[n] + 1);
    sequence[a[n]] = n;
    int i = n;
    while (i > 1)
    {
        if (pointer[i] == 1)
        {
            sequence[a[i - 1]] = sequence[a[i]] - 1;
            i--;
        }
        if (pointer[i] == 2)
        {
            sequence[a[i / 2]] = sequence[a[i]] >> 1;
            i /= 2;
        }
        if (pointer[i] == 3)
        {
            sequence[a[i / 3]] = sequence[a[i]] / 3;
            i /= 3;
        }
    }
    return sequence;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> sequence = optimal_sequence(n);
    std::cout << sequence.size() - 1 << std::endl;
    for (size_t i = 0; i < sequence.size(); i++)
    {
        std::cout << sequence[i] << " ";
    }
    return 0;
}
