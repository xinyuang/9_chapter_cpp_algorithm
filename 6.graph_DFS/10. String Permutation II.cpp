class Solution {
public:
	/**
	 * @param str: A string
	 * @return: all permutations
	 */
	vector<string> stringPermutation2(string& str) {
		// write your code here
		vector<string> res;
		string perm;
		sort(str.begin(), str.end());
		vector<bool> visited(str.size(), false);
		helper(str, res, perm, visited);
		return res;
	}

	void helper(string str, vector<string>& res, string& perm, vector<bool>& visited)
	{
		if (perm.size() == str.size())
		{
			res.push_back(perm);
			return;
		}

		for (int i = 0; i < str.size(); i++)
		{
			if (visited[i]) continue;
			if (i != 0 && str[i] == str[i - 1] && !visited[i - 1]) continue;
			perm.push_back(str[i]);
			visited[i] = true;
			helper(str, res, perm, visited);
			visited[i] = false;
			perm.erase(perm.size() - 1, 1);
		}
	}
};