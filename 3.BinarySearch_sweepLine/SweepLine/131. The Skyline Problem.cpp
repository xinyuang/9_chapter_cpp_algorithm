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
		if (buildings.size() == 0) return {};
		vector<vector<int>> points;  // [idx, height, in/out]
		flatten(buildings, points);
		class compare {
		public:
			bool operator()(const vector<int>& a, const vector<int>& b)
			{
				if (a[0] == b[0]) return a[2] < b[2];
				return a[0] < b[0];
			}
		} com;
		sort(points.begin(), points.end(), com);
		multiset<int> st;
		int i = 0;
		int last_height = -1;
		int cur_height = -1;
		vector<vector<int>> heights;
		while (i < points.size())
		{
			while (i < points.size() - 1 && points[i][0] == points[i + 1][0])
			{
				if (points[i][2] == 1) st.insert(points[i][1]);
				else {
					st.erase(st.find(points[i][1]));
				}
				i++;
			}
			if (points[i][2] == 1) st.insert(points[i][1]);
			else {
				st.erase(st.find(points[i][1]));
			}
			if (st.empty()) cur_height = 0;
			else cur_height = *st.rbegin();
			if (cur_height != last_height) heights.push_back({ points[i][0], cur_height });
			last_height = cur_height;
			i++;
		}
		int last_idx = heights[0][0];
		vector<vector<int>> res;
		for (int i = 1; i < heights.size(); i++)
		{
			if (heights[i - 1][1] == 0) continue;
			res.push_back({ heights[i - 1][0],heights[i][0],heights[i - 1][1] });
		}
		return res;
	}

	void flatten(vector<vector<int>>& buildings, vector<vector<int>>& points)
	{
		for (int i = 0; i < buildings.size(); i++)
		{
			points.push_back({ buildings[i][0],buildings[i][2],1 });
			points.push_back({ buildings[i][1],buildings[i][2],-1 });
		}
	}
};