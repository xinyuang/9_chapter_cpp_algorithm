//602. Russian Doll Envelopes
//sort envelop, auto it = lower_bount(LIS.begin(), LIS.end(), cur)
//if find then replace, otherwize push_back cur, return LIS.size()

class Solution {
public:
	/*
	 * @param envelopes: a number of envelopes with widths and heights
	 * @return: the maximum number of envelopes
	 */
	int maxEnvelopes(vector<pair<int, int>>& envelopes) {
		// write your code here
		class compare {
		public:
			bool operator()(const pair<int, int>& a, const pair<int, int>& b)
			{
				if (a.first == b.first) return a.second > b.second;
				return a.first < b.first;
			}
		} com;
		sort(envelopes.begin(), envelopes.end(), com);
		vector<int> LIS;
		for (int i = 0; i < envelopes.size(); i++)
		{
			int cur = envelopes[i].second;
			auto it = lower_bound(LIS.begin(), LIS.end(), cur);
			if (it == LIS.end()) LIS.push_back(cur);
			else *it = cur;
		}
		return LIS.size();
	}
};