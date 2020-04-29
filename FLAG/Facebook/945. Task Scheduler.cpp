//945. Task Scheduler

// priority_queue to simulate (n+1) slot rolling update result
class Solution {
public:
	/**
	 * @param tasks: the given char array representing tasks CPU need to do
	 * @param n: the non-negative cooling interval
	 * @return: the least number of intervals the CPU will take to finish all the given tasks
	 */
	int leastInterval(string& tasks, int n) {
		// write your code here
		priority_queue<int> max_heap;
		unordered_map<char, int> mp;
		for (int i = 0; i < tasks.size(); i++)
		{
			mp[tasks[i]]++;
		}
		for (auto e : mp)
		{
			max_heap.push(e.second);
		}
		int times = 0;
		while (!max_heap.empty())
		{
			vector<int> tmp;
			for (int i = 0; i <= n; i++)
			{
				if (!max_heap.empty())
				{
					int top = max_heap.top(); max_heap.pop();
					if (top > 1) tmp.push_back(top - 1);
				}
				else if (tmp.size() == 0) break;
				times++;
			}
			for (int i = 0; i < tmp.size(); i++)
			{
				max_heap.push(tmp[i]);
			}
		}
		return times;
	}
};


//      1      n
//     | |	.....   |
//     | |	...		|
//     | |	..		|
// ------------------------------
//     | |			|
class Solution {
public:
	/**
	 * @param tasks: the given char array representing tasks CPU need to do
	 * @param n: the non-negative cooling interval
	 * @return: the least number of intervals the CPU will take to finish all the given tasks
	 */
	int leastInterval(string& tasks, int n) {
		// write your code here
		unordered_map<char, int> mp;
		int max_count = 0;
		for (int i = 0; i < tasks.size(); i++)
		{
			mp[tasks[i]]++;
			max_count = max(max_count, mp[tasks[i]]);
		}
		int idle_slots = (max_count - 1) * (n + 1);
		for (auto e : mp)
		{
			idle_slots -= min(max_count - 1, e.second);
		}
		return max(idle_slots, 0) + tasks.size();
	}
};