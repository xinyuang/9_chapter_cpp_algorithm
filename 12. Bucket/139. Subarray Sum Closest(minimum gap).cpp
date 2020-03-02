//139. Subarray Sum Closest
//1. sort presum(value, idx), get the minimum gap

class Solution {
public:
	/*
	 * @param nums: A list of integers
	 * @return: A list of integers includes the index of the first number and the index of the last number
	 */
	vector<int> subarraySumClosest(vector<int>& nums) {
		// write your code here
		vector<pair<int, int>> v_p = { {0,-1} };
		int presum = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			presum += nums[i];
			v_p.push_back({ presum,i });
		}
		class compare {
		public:
			bool operator()(const pair<int, int>& a, const pair<int, int>& b)
			{
				if (a.first == b.first) return a.second < b.second;
				return a.first < b.first;
			}
		} com;
		sort(v_p.begin(), v_p.end(), com);
		int min_gap = INT_MAX;
		vector<int> res = { -1,-1 };
		for (int i = 1; i < v_p.size(); i++)
		{
			if (abs(v_p[i].first - v_p[i - 1].first) <= min_gap)
			{
				min_gap = abs(v_p[i].first - v_p[i - 1].first);
				res[0] = min(v_p[i].second, v_p[i - 1].second) + 1;
				res[1] = max(v_p[i].second, v_p[i - 1].second);
			}
		}
		return res;
	}
};
