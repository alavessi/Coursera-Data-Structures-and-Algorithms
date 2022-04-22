#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

struct Query
{
    std::string type, s;
    size_t ind;
};

class QueryProcessor
{
    int bucket_count;
    std::vector<std::list<std::string>> chains;
    size_t hash_func(const std::string& s) const
    {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; i--)
        {
            hash = (hash * multiplier + s[i]) % prime;
        }
        return hash % bucket_count;
    }

public:
    explicit QueryProcessor(int bucket_count): bucket_count(bucket_count)
    {
        chains.resize(bucket_count);
    }

    Query readQuery() const
    {
        Query query;
        std::cin >> query.type;
        if (query.type != "check")
        {
            std::cin >> query.s;
        }
        else
        {
            std::cin >> query.ind;
        }
        return query;
    }

    void writeSearchResult(bool was_found) const
    {
        std::cout << (was_found ? "yes\n" : "no\n");
    }

    void processQuery(const Query& query)
    {
        if (query.type == "check")
        {
            for (const std::string& s : chains[query.ind])
            {
                std::cout << s << " ";
            }
            std::cout << "\n";
        }
        else
        {
            std::list<std::string>& chain = chains[hash_func(query.s)];
            std::list<std::string>::iterator it = std::find(chain.begin(), chain.end(), query.s);
            if (query.type == "find")
            {
                writeSearchResult(it != chain.end());
            }
            else if (query.type == "add")
            {
                if (it == chain.end())
                {
                    chain.push_front(query.s);
                }
            }
            else if (query.type == "del")
            {
                if (it != chain.end())
                {
                    chain.erase(it);
                }
            }
        }
    }

    void processQueries()
    {
        int n;
        std::cin >> n;
        for (int i = 0; i < n; i++)
        {
            processQuery(readQuery());
        }
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    std::cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
