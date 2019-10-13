// reverse words in a string
class Solution {
public:
	/*
	 * @param s: A string
	 * @return: A string
	 */
	string reverseWords(string& s) {
		// write your code here
		if (s == " ") return "";
		vector<string> elements = split(s, " ");
		if (elements.size() == 1) return s;
		string res = "";
		for (int i = elements.size() - 1; i >= 0; i--)
		{
			res += elements[i];
			if (i != 0) res += " ";
		}
		return res;
	}

	vector<string> split(string input, string delim)
	{
		vector<string> res;
		int last_idx = 0, idx = 0;
		while ((idx = input.find(delim, last_idx)) != string::npos)
		{
			string seg = input.substr(last_idx, idx - last_idx);
			last_idx = idx + 1;
			if (seg == "") continue;
			res.push_back(seg);

		}
		if (last_idx != input.size()) res.push_back(input.substr(last_idx));
		return res;
	}
};


class Solution {
	/**
	 * @param s : A string
	 * @return : A string
	 */
public:
	string reverseWords(string s) {
		string ss;
		//从后往前遍历s
		int i = s.length() - 1;
		while (i >= 0)
		{
			//跳过多余的空格
			while (i >= 0 && s[i] == ' ')
			{
				i--;
			}
			if (i < 0) break;
			if (ss.length() != 0)
				ss.push_back(' ');
			string temp;
			//从后往前记录一个单词，并将改单词翻转，因为单词并不需要翻转
			for (; i >= 0 && s[i] != ' '; i--)
				temp.push_back(s[i]);
			reverse(temp.begin(), temp.end());
			ss.append(temp);
		}
		s = ss;
		return s;
	}
};