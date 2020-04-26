1422. Maximum Score After Splitting a String

class Solution {
public:
	int maxScore(string s) {
		int cnt_0 = 0;
		int cnt_1 = 0;
		for (int i = 1; i < s.size(); i++)
		{
			if (s[i] == '1') cnt_1++;
		}
		int res = 0;
		for (int i = 1; i < s.size(); i++)
		{
			if (s[i - 1] == '0') cnt_0++;
			if (i != 1 && s[i - 1] == '1') cnt_1--;
			res = max(res, cnt_1 + cnt_0);
		}
		return res;
	}
};