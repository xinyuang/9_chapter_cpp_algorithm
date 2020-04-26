//1424. Diagonal Traverse II
//1. from bottom to top, push_back mp[r + c] vector
//2. iterate mp element, flatten the res

class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
		if (nums.size() == 0) return {};
		map<int, vector<int>> mp;
		for (int i = nums.size() - 1; i >= 0; i--)
		{
			for (int j = 0; j < nums[i].size(); j++)
			{
				if (!mp.count(i + j)) mp[i + j] = {};
				mp[i + j].push_back(nums[i][j]);
			}
		}
		vector<int> res;
		for (auto e : mp)
		{
			for (int i = 0; i < e.second.size(); i++)
			{
				res.push_back(e.second[i]);
			}
		}
		return res;
	}
}