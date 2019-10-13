// Russian doll envelopes
// sort with first edge small to large but second edge large to small
// fake Longest Increasing Sequence
class Solution {
public:
	/*
	 * @param envelope122. Largest Rectangle in Histogram
s: a number of envelopes with widths and heights
	 * @return: the maximum number of envelopes
	 */
	int maxEnvelopes(vector<pair<int, int>>& envelopes) {
		// write your code here
		class compare {
		public:
			bool operator()(pair<int, int> a, pair<int, int> b)
			{
				if (a.first == b.first) return b.second < a.second;
				return a.first < b.first;
			}
		} com;
		sort(envelopes.begin(), envelopes.end(), com);
		vector<int> res;
		for (int i = 0; i < envelopes.size(); i++)
		{
			auto it = lower_bound(res.begin(), res.end(), envelopes[i].second);
			if (it == res.end()) res.push_back(envelopes[i].second);
			else *it = envelopes[i].second;
		}
		return res.size();
	}
};