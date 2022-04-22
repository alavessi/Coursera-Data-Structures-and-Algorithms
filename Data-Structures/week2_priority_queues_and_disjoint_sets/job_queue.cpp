#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

class JobQueue
{
private:
  int num_workers_;
  std::vector<int> jobs_;

  std::vector<int> assigned_workers_;
  std::vector<long long> start_times_;

  void WriteResponse() const
  {
    for (size_t i = 0; i < jobs_.size(); i++)
    {
      std::cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData()
  {
    size_t m;
    std::cin >> num_workers_ >> m;
    jobs_.resize(m);
    for (size_t i = 0; i < m; i++)
    {
      std::cin >> jobs_[i];
    }
  }

  void AssignJobs()
  {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.reserve(jobs_.size());
    start_times_.reserve(jobs_.size());
    /*std::vector<long long> next_free_time(num_workers_, 0);
    for (size_t i = 0; i < jobs_.size(); i++)
    {
      int duration = jobs_[i];
      int next_worker = 0;
      for (int j = 0; j < num_workers_; j++)
      {
        if (next_free_time[j] < next_free_time[next_worker])
        {
          next_worker = j;
        }
      }
      assigned_workers_[i] = next_worker;
      start_times_[i] = next_free_time[next_worker];
      next_free_time[next_worker] += duration;
    }*/
    using Task = std::pair<long long, int>;
    std::priority_queue<Task, std::vector<Task>, std::greater<Task>> pq;
    for (int id = 0; id < num_workers_; id++)
    {
      pq.push({0, id});
    }
    for (auto job_time: jobs_)
    {
      auto [time, id] = pq.top();
      assigned_workers_.push_back(id);
      start_times_.push_back(time);
      pq.pop();
      pq.push({time + job_time, id});
    }
  }

 public:
  void Solve()
  {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main()
{
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
