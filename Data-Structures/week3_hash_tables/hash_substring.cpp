#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

struct Data
{
    std::string pattern, text;
};

Data read_input()
{
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const std::vector<int>& output)
{
    for (size_t i = 0; i < output.size(); i++)
    {
        std::cout << output[i] << " ";
    }
    std::cout << "\n";
}

size_t PolyHash(const std::string& s, size_t prime, size_t multiplier)
{
    size_t hash = 0;
    for (int i = static_cast<int> (s.size()) - 1; i >= 0; i--)
    {
        hash = (hash * multiplier + s[i]) % prime;
    }
    return hash;
}

std::vector<size_t> PrecomputeHashes(const std::string& T, size_t len_p, size_t prime, size_t x)
{
    std::vector<size_t> H(T.size() - len_p + 1);
    const std::string& S = T.substr(T.size() - len_p, len_p);
    H[T.size() - len_p] = PolyHash(S, prime, x);
    size_t y = 1;
    for (size_t i = 1; i <= len_p; i++)
    {
        y = (y * x) % prime;
    }
    for (int i = T.size() - len_p - 1; i >= 0; i--)
    {
        H[i] = (x * H[i + 1] + T[i] - y * T[i + len_p]) % prime;
    }
    return H;
}

std::vector<int> get_occurrences(const Data& input)
{
    const std::string& pattern = input.pattern, text = input.text;
    static const size_t prime = 1000000007;
    static const size_t x = 1 + rand() % (prime - 1);
    std::vector<int> result;
    size_t pHash = PolyHash(pattern, prime, x);
    std::vector<size_t> H = PrecomputeHashes(text, pattern.size(), prime, x);
    for (size_t i = 0; i <= text.size() - pattern.size(); i++)
    {
        if (H[i] != pHash) continue;
        if (text.substr(i, pattern.size()) == pattern)
        {
            result.push_back(i);
        }
    }
    return result;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
