//1408. String Matching in an Array
//str.find("matchstring", start_idx) == string::npos

class Solution {
public:
	vector<string> stringMatching(vector<string>& words) {
		set<string> res;
		for (int i = 0; i < words.size(); i++)
		{
			for (int j = 0; j < words.size(); j++)
			{
				if (i == j) continue;
				long idx = words[j].find(words[i], 0);
				if (idx >= 0 && idx < words[j].size())
				{
					res.insert(words[i]);
				}

			}
		}
		vector<string> ret(res.begin(), res.end());
		return ret;
	}
};