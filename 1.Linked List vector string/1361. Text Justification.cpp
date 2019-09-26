class Solution {
public:
	/**
	 * @param words: an array of string
	 * @param maxWidth: a integer
	 * @return: format the text such that each line has exactly maxWidth characters and is fully
	 */
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		// write your code here
		int count = 0;
		vector<string> candidate;
		vector<string> res;
		for (int i = 0; i < words.size(); i++)
		{
			if ((count + words[i].size()) <= maxWidth)
			{
				count = count + words[i].size() + 1;
				candidate.push_back(words[i]);
			}
			else
			{
				string ans = toString(candidate, maxWidth, false);
				res.push_back(ans);
				candidate.clear();
				candidate.push_back(words[i]);
				count = words[i].size() + 1;
			}
		}
		string ans = toString(candidate, maxWidth, true);
		res.push_back(ans);
		return res;
	}

	string toString(vector<string>& candidate, int maxWidth, bool end)
	{
		string res = "";
		string space;
		if (!end && candidate.size() > 1)
		{
			int len = 0;
			for (int i = 0; i < candidate.size(); i++)
			{
				len += candidate[i].size();
			}
			int remaian = maxWidth - len;
			int base = remaian / (candidate.size() - 1);
			int plus = remaian % (candidate.size() - 1);

			for (int i = 0; i < candidate.size() - 1; i++)
			{
				res += candidate[i];
				if (plus != 0 && i < plus) space.assign(base + 1, ' ');
				else space.assign(base, ' ');
				res += space;
			}
			res.append(candidate.back());
		}
		else
		{
			for (int i = 0; i < candidate.size(); i++)
			{
				res += candidate[i];
				if (res.size() < maxWidth) res += " ";
			}
			int remain = maxWidth - res.size();
			space.assign(remain, ' ');
			res += space;
		}
		return res;
	}
};