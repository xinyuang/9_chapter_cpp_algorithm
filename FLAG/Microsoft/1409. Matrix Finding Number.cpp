//1409. Matrix Finding Number
//map<int, int> store line count.only mp number == cur line idx, mp[c] = i + 1,
//check the first one mp[e] == mat.size()

class Solution {
public:
	/**
	 * @param mat: The matrix
	 * @return: The answer
	 */
	int findingNumber(vector<vector<int>>& mat) {
		// Write your code here
		map<int, int> mp;
		for (int i = 0; i < mat.size(); i++)
		{
			for (int j = 0; j < mat[0].size(); j++)
			{
				if (i == 0) mp[mat[i][j]]++;
				if (mp[mat[i][j]] == i) mp[mat[i][j]] = i + 1;
			}
		}
		for (auto e : mp)
		{
			if (e.second == mat.size()) return e.first;
		}
		return -1;
	}
};