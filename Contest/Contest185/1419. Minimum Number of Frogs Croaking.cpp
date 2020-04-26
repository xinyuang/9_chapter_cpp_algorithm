//1419. Minimum Number of Frogs Croaking
//1. get histogram of 'c', 'r', 'o', 'a', 'k'
//2. check mp['c'] > mp['r'] > mp['o'] > mp['a'] > mp['k']
//3. res = max(res, mp['k'] - mp['c'])

class Solution {
public:
	int minNumberOfFrogs(string croakOfFrogs) {
		string str = croakOfFrogs;
		string valid = "croak";
		vector<int> mp(5, 0);
		int res = 0;
		for (int i = 0; i < str.size(); i++)
		{
			for (int j = 0; j < valid.size(); j++)
			{
				if (str[i] == valid[j]) {
					mp[j]++;
					if (j != 0 && mp[j] > mp[j - 1]) return -1;
				}
			}
			res = max(res, mp[0] - mp.back());
		}
		for (int i = 1; i < valid.size(); i++)
		{
			if (mp[i] != mp[i - 1]) return -1;
		}
		return res;
	}
};