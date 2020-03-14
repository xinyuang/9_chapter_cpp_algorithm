//1221. Concatenated Words
//k word break
//1. k word break, for loop str.size instead of word set
//2. if word[i].size() == 0 || substr == cur_word continue

class Solution {
public:
	/**
	 * @param words: List[str]
	 * @return: return List[str]
	 */
	vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
		// write your code here
		unordered_set<string> wd;
		for (int i = 0; i < words.size(); i++)
		{
			wd.insert(words[i]);
		}
		vector<string> res;
		for (string str : wd)
		{
			vector<int> dp(str.size() + 1, 0);
			dp[0] = 1;
			for (int i = 0; i < str.size(); i++)
			{
				for (int j = 0; j <= i; j++)
				{
					string cur_str = str.substr(j, i - j + 1);

					if (wd.count(cur_str) && cur_str != str) {
						dp[i + 1] = dp[i + 1] || dp[j];
					}
				}
			}
			if (dp.back() == 1 && dp.size() > 1) res.push_back(str);
		}
		return res;
	}
};