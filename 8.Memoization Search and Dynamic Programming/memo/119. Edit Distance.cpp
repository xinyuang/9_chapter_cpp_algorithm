// Edit Distance
//   doog dog
//      .   .
class Solution {
public:
	/**
	 * @param word1: A string
	 * @param word2: A string
	 * @return: The minimum number of steps.
	 */
	int minDistance(string& word1, string& word2) {
		// write your code here
		vector<vector<int>> memo(word1.size(), vector<int>(word2.size(), -1));
		int res = search(word1, 0, word2, 0, memo);
		return res;
	}

	int search(string& one, int s, string& two, int t, vector<vector<int>>& memo)
	{
		if (s == one.size()) return two.size() - t;
		if (t == two.size()) return one.size() - s;
		if (memo[s][t] != -1) return memo[s][t];
		int min_dist = INT_MAX;
		if (one[s] == two[t])
		{
			min_dist = search(one, s + 1, two, t + 1, memo);
		}
		else
		{
			int replace_ = search(one, s + 1, two, t + 1, memo);
			int delete_ = search(one, s + 1, two, t, memo);
			int insert_ = search(one, s, two, t + 1, memo);
			min_dist = (replace_ < delete_ ? replace_ : delete_);
			min_dist = (min_dist < insert_ ? min_dist : insert_);
			min_dist++;
		}
		memo[s][t] = min_dist;
		return min_dist;
	}
};

class Solution {
public:
	/**
	 * @param word1: A string
	 * @param word2: A string
	 * @return: The minimum number of steps.
	 */
	int minDistance(string& word1, string& word2) {
		// write your code here
		vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
		for (int i = 0; i <= word1.size(); i++) dp[i][0] = i;
		for (int i = 0; i <= word2.size(); i++) dp[0][i] = i;
		for (int i = 1; i <= word1.size(); i++)
		{
			for (int j = 1; j <= word2.size(); j++)
			{
				if (word1[i - 1] == word2[j - 1])
				{
					dp[i][j] = dp[i - 1][j - 1];
				}
				else
				{
					dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
				}
			}
		}
		return dp[word1.size()][word2.size()];
	}

};
