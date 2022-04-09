#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> fast_count_segments(std::vector<int>& starts, std::vector<int>& ends, const std::vector<int>& points)
{
    std::vector<int> cnt(points.size());
    int a, b;
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());
    for (size_t i = 0; i < points.size(); i++)
    {
        if (points[i] >= starts[starts.size() - 1])
        {
            a = starts.size();
        }
        if (points[i] < starts[0])
        {
            a = 0;
        }
        if (points[i] >= starts[0] && points[i] < starts[starts.size() - 1])
        {
            int left = 0, right = (int)starts.size() - 1;
            while (left < right)
            {
                int middle = (left + right) / 2;
                if (starts[middle] <= points[i])
                {
                    left = middle + 1;
                }
                else
                {
                    right = middle;
                }
            }
            a = right;
        }
        if (points[i] > ends[ends.size() - 1])
        {
            b = 0;
        }
        if (points[i] <= ends[0])
        {
            b = ends.size();
        }
        if (points[i] > ends[0] && points[i] <= ends[ends.size() - 1])
        {
            int left = 0, right = (int)ends.size() - 1;
            while(left < right)
            {
                int middle = (left + right) / 2;
                if (ends[middle] < points[i])
                {
                    left = middle + 1;
                }
                else
                {
                    right = middle;
                }
            }
            b = ends.size() - left;
        }
        cnt[i] = a + b - starts.size();
    }
    return cnt;
}

std::vector<int> naive_count_segments(const std::vector<int>& starts, const std::vector<int>& ends, const std::vector<int>& points)
{
    std::vector<int> cnt(points.size());
    for (size_t i = 0; i < points.size(); i++)
    {
        for (size_t j = 0; j < starts.size(); j++)
        {
            cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
        }
    }
    return cnt;
}

int main()
{
    size_t s, p;
    std::cin >> s >> p;
    std::vector<int> starts(s), ends(s);
    for (size_t i = 0; i < s; i++)
    {
        std::cin >> starts[i] >> ends[i];
    }
    std::vector<int> points(p);
    for (size_t i = 0; i < p; i++)
    {
        std::cin >> points[i];
    }
    std::vector<int> cnt = fast_count_segments(starts, ends, points);
    for (size_t i = 0; i < p; i++)
    {
        std::cout << cnt[i] << " ";
    }
    return 0;
}
