#include <iostream>
#include <algorithm>
#include <vector>

struct Segment
{
    int start,end;
};

std::vector<int> optimal_points(std::vector<Segment> &segments)
{
    std::vector<int> points;
    int last = 0;
    std::sort(segments.begin(),segments.end(), [] (Segment a, Segment b) -> bool {return a.end < b.end;});
    points.push_back(segments[0].end);
    for (unsigned int i=0; i<segments.size(); i++)
    {
        if(segments[i].start > segments[last].end)
        {
            points.push_back(segments[i].end);
            last = i;
        }
    }
    return points;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<Segment> segments(n);
    for (int i=0; i<n; i++)
    {
        std::cin >> segments[i].start >> segments[i].end;
    }
    std::vector<int> points = optimal_points(segments);
    std::cout << points.size() << std::endl;
    for (unsigned int i=0; i<points.size(); i++)
    {
        std::cout << points[i] << " ";
    }
    return 0;
}
