#include <iostream>
#include <vector>
#include <string>

struct Query
{
    std::string type, name;
    int number;
};

std::vector<Query> read_queries()
{
    int n;
    std::cin >> n;
    std::vector<Query> queries(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> queries[i].type >> queries[i].number;
        if (queries[i].type == "add")
        {
            std::cin >> queries[i].name;
        }
    }
    return queries;
}

void write_responses(const std::vector<std::string>& result)
{
    for (size_t i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << "\n";
    }
}

std::vector<std::string> process_queries(const std::vector<Query>& queries)
{
    std::vector<std::string> result;
    const size_t MAXSIZE = 1e7;
    std::vector<std::string> table(MAXSIZE); // using direct addressing
    for (const Query& query: queries)
    {
        if (query.type == "add")
        {
            table[query.number] = query.name;
        }
        else if (query.type == "del")
        {
            table[query.number].clear();
        }
        else
        {
            std::string response = table[query.number];
            if (response.empty())
            {
                response = "not found";
            }
            result.push_back(response);
        }
    }
    return result;
}

int main()
{
    write_responses(process_queries(read_queries()));
    return 0;
}
