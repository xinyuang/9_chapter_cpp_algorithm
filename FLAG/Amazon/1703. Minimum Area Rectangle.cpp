//1703. Minimum Area Rectangle
//1. sort by column, if in same column, sort row from small to large
//2. for loop, fix cur point, find left up point, right bottom point, and right up point, get min area

class Solution {
public:
	/**
	 * @param points: a set of points
	 * @return: the min area
	 */
	int minimumAreaRectangle(vector<vector<int>>& points) {
		// Write your code here.
		class compare {
		public:
			bool operator()(const vector<int>& a, const vector<int>& b)
			{
				if (a[1] == b[1]) return a[0] < b[0];
				return a[1] < b[1];
			}
		} com;
		sort(points.begin(), points.end(), com);
		int min_area = INT_MAX;
		for (int c = 0; c < points.size(); c++)
		{
			for (int lu = c + 1; lu < points.size(); lu++)
			{
				if (points[lu][1] != points[c][1]) break;
				int height1 = points[lu][0] - points[c][0];
				for (int rb = lu + 1; rb < points.size(); rb++)
				{
					if (points[rb][0] != points[c][0]) continue;
					int width = points[rb][1] - points[c][1];
					for (int ru = rb + 1; ru < points.size(); ru++)
					{
						if (points[ru][1] != points[rb][1]) break;
						int height2 = points[ru][0] - points[rb][0];
						if (height2 != height1) continue;
						min_area = min(min_area, height1 * width);
					}
				}
			}
		}
		if (min_area == INT_MAX) return 0;
		return min_area;
	}
};