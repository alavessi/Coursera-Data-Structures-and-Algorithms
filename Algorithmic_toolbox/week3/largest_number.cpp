#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

std::string largest_number (std::vector<std::string> a)
{
    std::sort(a.begin(),a.end(), [] (std::string a, std::string b) -> bool {return a+b > b+a;});
    std::stringstream ret;
    for (unsigned int i=0; i<a.size(); i++)
    {
        ret << a[i];
    }
    std::string result;
    ret >> result;
    return result;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::string> a(n);
    for (unsigned int i=0; i<a.size(); i++)
    {
        std::cin >> a[i];
    }
    std::cout << largest_number(a);
    return 0;
}
