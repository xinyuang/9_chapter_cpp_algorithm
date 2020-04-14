//131. The Skyline Problem
//1. sort rectangles
//2. in the same idx, use multiset + -height, store max_height

class Solution {
public:
	/**
	 * @param buildings: A list of lists of integers
	 * @return: Find the outline of those buildings
	 */
	vector<vector<int>> buildingOutline(vector<vector<int>>& buildings) {
		// write your code here
		vector<vector<int>> line;
		for (int i = 0; i < buildings.size(); i++)
		{
			line.push_back({ buildings[i][0],buildings[i][2],1 });
			line.push_back({ buildings[i][1],buildings[i][2],-1 });
		}
		class compare {
		public:
			bool operator()(const vector<int>& a, const vector<int>& b)
			{
				if (a[0] == b[0]) return a[2] < b[2];
				return a[0] < b[0];
			}
		} com;
		sort(line.begin(), line.end(), com);
		multiset<int> st;
		int i = 0;
		int cur_hight = 0;
		int last_idx = -1;
		vector<vector<int>> res;
		for (int i = 0; i < line.size(); i++)
		{
			int cur_idx = line[i][0];
			while (i < line.size() - 1 && line[i][0] == line[i + 1][0])
			{
				if (line[i][2] > 0) st.insert(line[i][1]);
				else {
					if (!st.empty()) st.erase(st.find(line[i][1]));
				}
				i++;
			}
			if (line[i][2] > 0) st.insert(line[i][1]);
			else st.erase(st.find(line[i][1]));
			int new_hight = 0;
			if (!st.empty())new_hight = *st.rbegin();
			if (cur_hight != new_hight)
			{
				if (cur_hight != 0 && last_idx != cur_idx) res.push_back({ last_idx,cur_idx,cur_hight });
				last_idx = cur_idx;
			}
			cur_hight = new_hight;
		}
		return res;
	}
};