#include <iostream>
#include <string>

int edit_distance(const std::string& s1, const std::string& s2)
{
    int D[s1.size() + 1][s2.size() + 1];
    for (size_t i = 0; i <= s1.size(); i++)
    {
        D[i][0] = i;
    }
    for (size_t j = 0; j <= s2.size(); j++)
    {
        D[0][j] = j;
    }
    for (size_t i = 1; i <= s1.size(); i++)
    {
        for (size_t j = 1; j <= s2.size(); j++)
        {
            D[i][j] = std::min(D[i - 1][j] + 1, D[i][j - 1] + 1);
            D[i][j] = (s1[i - 1] == s2[j - 1]) ? std::min(D[i][j], D[i - 1][j - 1]) : std::min(D[i][j], D[i - 1][j - 1] + 1);
        }
    }
    return D[s1.size()][s2.size()];
}

int main()
{
    std::string str1, str2;
    std::cin >> str1 >> str2;
    std::cout << edit_distance(str1, str2);
    return 0;
}
