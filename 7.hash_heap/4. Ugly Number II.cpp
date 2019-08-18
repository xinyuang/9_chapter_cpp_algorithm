class Solution {
public:
	/**
	 * @param n: An integer
	 * @return: return a  integer as description.
	 */
	int nthUglyNumber(int n) {
		// write your code here
		int ptr[3] = { 0 };
		int ugly[3] = { 2,3,5 };
		vector<int> cur = { 1 };
		while (cur.size() < n)
		{
			int add_idx = -1;
			int cur_min = INT_MAX;
			for (int j = 0; j < 3; j++)
			{
				int candidate = cur[ptr[j]] * ugly[j];
				if (candidate < cur_min)
				{
					cur_min = candidate;
					add_idx = j;
				}
			}
			ptr[add_idx]++;
			if (cur_min == cur.back()) continue;
			cur.push_back(cur_min);
		}
		return cur.back();
	}
};