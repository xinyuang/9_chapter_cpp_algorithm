// Anagrams
// sort string as key of unordered_map
class Solution {
public:
	/**
	 * @param strs: A list of strings
	 * @return: A list of strings
	 */
	vector<string> anagrams(vector<string>& strs) {
		// write your code here
		unordered_map<string, vector<string>> map;
		for (int i = 0; i < strs.size(); i++)
		{
			string cur = strs[i];
			sort(cur.begin(), cur.end());
			map[cur].push_back(strs[i]);
		}
		vector<string> res;
		for (auto item : map)
		{
			if (item.second.size() >= 2)
			{
				for (string str : item.second)
					res.push_back(str);
			}
		}
		return res;
	}
};