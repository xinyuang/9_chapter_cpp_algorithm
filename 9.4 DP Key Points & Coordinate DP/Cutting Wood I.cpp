//L = 10, A = {2, 4, 7}, 
//the minimum total cost is 10 + 4 + 6 = 20 (cut at 4 first then cut at 2 and cut at 7)
//  devide and conquer , return min cost between range, add a memo
//        [0,10]                          
//    [0,1][2,10]              2+9
//  [0,1][2,3][4,10]          2 + 7
//            [4,6][7,10]      3 + 4


//        [0,10]
//    [0,3][4,10]           4 + 7
//  [0,1][2,3][4,10]      2 + 2
//            [4,6][7,10]    3 + 4

//        [0,10]
//    [0,6][7,10]          7 + 4
//  [0,1][2,6][7,10]       2 + 5
//     [2,3][4,6]            2 + 3

class Solution {
public:
	int minCost(vector<int> cuts, int length) {
		// write your solution here
		pair<int, int> range = { 0,length - 1 };
		vector<vector<int>> dp(length, vector<int>(length, -1));
		int res = findMin(cuts, length, range, dp);
		return res - length;
	}

	int findMin(vector<int>& cuts, int length, pair<int, int> range, vector<vector<int>>& dp)
	{
		vector<int> next_cuts;
		if (range.first > range.second) return 0;
		if (dp[range.first][range.second] != -1) return dp[range.first][range.second];
		for (int i = 0; i < cuts.size(); i++)
		{
			if (!in_range(cuts[i], range)) continue;
			next_cuts.push_back(cuts[i]);
		}
		if (next_cuts.size() == 0) return range.second - range.first + 1;
		int res = INT_MAX;
		for (int next : next_cuts)
		{
			int pre = findMin(cuts, length, { range.first,next - 1 }, dp);
			int pos = findMin(cuts, length, { next,range.second }, dp);
			int candidate = pre + pos;
			if (candidate < res) res = candidate;
		}
		res = res + range.second - range.first + 1;
		dp[range.first][range.second] = res;
		return res;
	}

	bool in_range(int tar, pair<int, int> range)
	{
		if (tar > range.first && tar <= range.second) return true;
		return false;
	}
};
