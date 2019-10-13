// 892. Alien Dictionary
class Solution {
public:
	/**
	 * @param words: a list of words
	 * @return: a string which is correct order
	 */
	string alienOrder(vector<string>& words) {
		// Write your code here
		unordered_map<char, vector<char>> graph;
		unordered_map<char, int> indegree;
		set<char> chars;
		for (int i = 0; i < words.size() - 1; i++)
		{
			string first = words[i];
			string second = words[i + 1];
			int f_ptr = 0, s_ptr = 0;
			chars.insert(first.begin(), first.end());
			while (f_ptr != first.size() && s_ptr != second.size())
			{
				if (first[f_ptr] != second[s_ptr]) break;
				f_ptr++; s_ptr++;
			}
			graph[first[f_ptr]].push_back(second[s_ptr]);
			if (f_ptr != first.size() && s_ptr != second.size() && first[f_ptr] != second[s_ptr]) indegree[second[s_ptr]]++;
		}
		chars.insert(words.back().begin(), words.back().end());

		set<char> candidates = chars;

		for (auto ele : indegree)
		{
			candidates.erase(ele.first);
		}
		string res = "";
		while (!candidates.empty())
		{
			char cur = *begin(candidates); candidates.erase(cur);
			res += cur;
			vector<char> neighbors = graph[cur];
			graph.erase(cur);
			for (char c : neighbors)
			{
				indegree[c]--;
				if (indegree[c] == 0) candidates.insert(c);
			}
		}
		if (res.size() != chars.size()) return "";
		return res;
	}
};