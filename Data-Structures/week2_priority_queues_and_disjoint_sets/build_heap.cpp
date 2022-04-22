#include <iostream>
#include <vector>
#include <algorithm>

class HeapBuilder
{
private:
  std::vector<int> data_;
  std::vector<std::pair<int, int>> swaps_;

  void WriteResponse() const
  {
    std::cout << swaps_.size() << "\n";
    for (size_t i = 0; i < swaps_.size(); i++)
    {
      std::cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData()
  {
    int n;
    std::cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; i++)
    {
      std::cin >> data_[i];
    }
  }

  void sift_down(size_t i)
  {
    while (2 * i + 1 < data_.size())
    {
      size_t left = 2 * i + 1;
      size_t right = 2 * i + 2;
      size_t j = left;
      if (right < data_.size() and data_[right] < data_[left])
      {
        j = right;
      }
      if (data_[i] <= data_[j])
      {
        break;
      }
      swaps_.push_back(std::make_pair(i, j));
      std::swap(data_[i], data_[j]);
      i = j;
    }
  }

  void build()
  {
    for (int i = data_.size() / 2; i >= 0; i--)
    {
      sift_down(i);
    }
  }

  void GenerateSwaps()
  {
    swaps_.clear();
    build();
  }

public:
  void Solve()
  {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main()
{
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
