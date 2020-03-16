//1383. Maximum Performance of a Team
//performance = sum(speed) * min(efficiency)
//1. sort pair speed, efficiency based on efficiency
//2. priority_queue min_heap store topK speed
//3. for loop from right to left to void duplicate calculation

class Solution {
public:
	int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
		vector<pair<int, int>> se;
		for (int i = 0; i < speed.size(); i++)
		{
			se.push_back({ speed[i], efficiency[i] });
		}
		class compare {
		public:
			bool operator()(const pair<int, int>& a, const pair<int, int>& b)
			{
				return a.second < b.second;
			}
		} com;
		long max_res = 0;
		sort(se.begin(), se.end(), com);
		priority_queue<int, vector<int>, greater<int>> min_heap;
		long speed_sum = 0;
		for (int i = se.size() - 1; i >= 0; i--)
		{
			long min_eff = se[i].second;
			if (min_heap.size() >= k)
			{
				speed_sum -= min_heap.top();
				min_heap.pop();
			}
			speed_sum += se[i].first;
			min_heap.push(se[i].first);
			long cur_res = (min_eff * speed_sum);
			max_res = max(max_res, cur_res);
		}
		return max_res % (long)(pow(10, 9) + 7);
	}
};