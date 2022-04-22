#include <iostream>
#include <vector>
#include <algorithm>

struct DisjointSetsElement
{
	int size, parent, rank;

	DisjointSetsElement(int size = 0, int parent = -1, int rank = 0): size(size), parent(parent), rank(rank) {}
};

struct DisjointSets
{
	int size;
	int max_table_size;
	std::vector<DisjointSetsElement> sets;

	DisjointSets(int size): size(size), max_table_size(0), sets(size)
	{
		for (int i = 0; i < size; i++)
		{
			sets[i].parent = i;
		}
	}

	int getParent(int table)
	{
		// find parent and compress path
		if (table != sets[table].parent)
		{
			sets[table].parent = getParent(sets[table].parent);
		}
		return sets[table].parent;
	}

	void merge(int destination, int source)
	{
		int realDestination = getParent(destination);
		int realSource = getParent(source);
		if (realDestination != realSource)
		{
			// merge two components
			// use union by rank heuristic
                        // update max_table_size

			max_table_size = std::max(max_table_size, sets[realSource].size + sets[realDestination].size);
			if (sets[realDestination].rank > sets[realSource].rank)
			{
				sets[realSource].parent = realDestination;
				sets[realDestination].size += sets[realSource].size;
			}
			else
			{
				sets[realDestination].parent = realSource;
				sets[realSource].rank += sets[realDestination].rank == sets[realSource].rank;
				sets[realSource].size += sets[realDestination].size;
			}
		}		
	}
};

int main()
{
	int n, m;
	std::cin >> n >> m;

	DisjointSets tables(n);
	for (auto& table : tables.sets)
	{ 
		std::cin >> table.size;
		tables.max_table_size = std::max(tables.max_table_size, table.size);
	}

	for (int i = 0; i < m; i++)
	{
		int destination, source;
		std::cin >> destination >> source;
		tables.merge(destination - 1, source - 1);
	    std::cout << tables.max_table_size << std::endl;
	}

	return 0;
}
