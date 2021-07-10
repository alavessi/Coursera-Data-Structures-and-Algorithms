#include <iostream>
#include <vector>

int compute_min_refills(int dist, int tank, int n, std::vector<int> &stops)
{
    int numRefills=0, currentRefill=0, lastRefill;
    while(currentRefill <= n)
    {
        lastRefill = currentRefill;
        while(currentRefill <= n && stops[currentRefill+1] - stops[lastRefill] <= tank)
            currentRefill++;
        if(currentRefill == lastRefill)
            return -1;
        if(currentRefill <= n)
            numRefills++;
    }
    return numRefills;
}

int main()
{
    int d,m,n;
    std::cin >> d >> m >> n;
    std::vector<int> stops(n+2);
    for (int i=1; i<=n; i++)
        std::cin >> stops[i];
    stops[0] = 0;
    stops[n+1] = d;
    std::cout << compute_min_refills(d, m, n, stops);
    return 0;
}
