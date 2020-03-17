//1369. Most Common Word
//1. split isalpha(char)
//2. unordered_map count, filter out banned

class Solution {
public:
	/**
	 * @param paragraph:
	 * @param banned:
	 * @return: nothing
	 */
	string mostCommonWord(string& paragraph, vector<string>& banned) {
		// 
		unordered_set<string> ban(banned.begin(), banned.end());
		unordered_map<string, int> mp;
		int i = 0;
		int most = 0;
		string res = "";
		while (i < paragraph.size())
		{
			string new_word = "";
			while (i < paragraph.size() && isalpha(paragraph[i]))
			{

				new_word.push_back(paragraph[i++]);
			}
			i++;
			transform(new_word.begin(), new_word.end(), new_word.begin(), ::tolower);
			if (!ban.count(new_word) && new_word != "")
			{
				mp[new_word]++;
				if (mp[new_word] > most)
				{
					res = new_word;
					most = mp[new_word];
				}
			}
		}
		return res;
	}
};