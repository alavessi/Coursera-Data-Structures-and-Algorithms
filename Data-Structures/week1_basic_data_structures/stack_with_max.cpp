#include <iostream>
#include <stack>
#include <string>
#include <cassert>

class StackWithMax
{
public:
    void push(int value)
    {
        data.push({value, data.empty() ? value : std::max(value, data.top().second)});
    }

    void pop()
    {
        assert(!data.empty());
        data.pop();
    }

    int max() const
    {
        assert(!data.empty());
        return data.top().second;
    }

private:
    std::stack<std::pair<int, int>> data;
};

int main()
{
    int num_queries = 0;
    std::cin >> num_queries;
    StackWithMax st;
    for (int i = 0; i < num_queries; i++)
    {
        std::string query;
        std::cin >> query;
        if (query == "push")
        {
            int value;
            std::cin>>value;
            st.push(value);
        }
        else if (query=="pop")
        {
            st.pop();
        }
        else if (query == "max")
        {
            std::cout << st.max() << std::endl;
        }
        else
        {
            assert(0);
        }
    }
    return 0;
}
