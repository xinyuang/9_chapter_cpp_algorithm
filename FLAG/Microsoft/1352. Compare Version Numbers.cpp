//1352. Compare Version Numbers
//version.split('.') compare stoi(ele) or return the longer one

class Solution {
public:
	/**
	 * @param version1: the first given number
	 * @param version2: the second given number
	 * @return: the result of comparing
	 */
	int compareVersion(string& version1, string& version2) {
		// Write your code here
		vector<int> res1 = chunckStr(version1, '.');
		vector<int> res2 = chunckStr(version2, '.');
		int p1 = 0, p2 = 0;
		while (p1 < res1.size() && p2 < res2.size())
		{
			if (res1[p1] < res2[p2])
			{
				return -1;
			}
			else if (res1[p1] > res2[p2])
			{
				return 1;
			}
			p1++; p2++;
		}
		if (p1 < res1.size()) return 1;
		if (p2 < res2.size()) return -1;
		return 0;
	}

	vector<int> chunckStr(string s, char del)
	{
		vector<int> res;
		string cur = "";
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == del)
			{
				res.push_back(stoi(cur));
				cur = "";
			}
			else
			{
				cur.push_back(s[i]);
			}
		}
		if (cur != "") res.push_back(stoi(cur));
		return res;
	}
};