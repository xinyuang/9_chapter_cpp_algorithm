//1361. Text Justification
//1. if have enough space, push_back candidate, otherwise clearand push first
//2. adjust space convert candidate vector to string

class Solution {
public:
	/**
	 * @param words: an array of string
	 * @param maxWidth: a integer
	 * @return: format the text such that each line has exactly maxWidth characters and is fully
	 */
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		// write your code here
		vector<string> candidate;
		vector<string> res;
		int cur_len = 0;
		for (int i = 0; i < words.size(); i++)
		{
			if (cur_len + (int)words[i].size() <= maxWidth)
			{
				candidate.push_back(words[i]);
				cur_len += (int)words[i].size() + 1;
			}
			else
			{
				string line = toString(candidate, maxWidth, false);
				res.push_back(line);
				candidate.clear();
				candidate.push_back(words[i]);
				cur_len = (int)words[i].size() + 1;
			}
		}
		if (candidate.size() != 0)
		{
			string line = toString(candidate, maxWidth, true);
			res.push_back(line);
		}
		return res;
	}

	string toString(vector<string>& candidate, int maxWidth, bool isEnd)
	{
		int sum_len = 0;
		for (int i = 0; i < candidate.size(); i++)
		{
			sum_len += candidate[i].size();
		}
		string res = "";
		if (isEnd || candidate.size() == 1)
		{
			for (int i = 0; i < candidate.size(); i++)
			{
				res += candidate[i];
				if (res.size() < maxWidth) res += " ";
			}
			int remain = maxWidth - (int)res.size();
			if (remain > 0) res += string(remain, ' ');
		}
		else
		{
			int remain = maxWidth - sum_len;
			int base = remain / ((int)candidate.size() - 1);
			int plus = remain % ((int)candidate.size() - 1);
			for (int i = 0; i + 1 < candidate.size(); i++)
			{
				string space;
				if (i < plus) space = string(base + 1, ' ');
				else space = string(base, ' ');
				res += candidate[i] + space;
			}
			res += candidate.back();
		}
		return res;
	}
};