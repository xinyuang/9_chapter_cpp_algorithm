1410. HTML Entity Parser

class Solution {
public:
	string entityParser(string text) {
		unordered_map<string, string> mp = { {"quot;","\""}, {"apos;","\'"},{"amp;","&"},{"gt;",">"},{"lt;","<"},{"frasl;","/"} };
		string res = "";
		for (int i = 0; i < text.size(); i++)
		{
			if (text[i] == '&')
			{
				bool flag = false;
				for (auto ele : mp)
				{
					long next = text.find(ele.first, i);
					if (next == string::npos) continue;
					if (text.substr(i + 1, ele.first.size()) == ele.first)
					{
						flag = true;
						res += mp[ele.first];
						i = next + ele.first.size() - 1;
						break;
					}
				}
				if (flag == false)res.push_back(text[i]);
			}
			else
			{
				res.push_back(text[i]);
			}
		}
		return res;
	}
};