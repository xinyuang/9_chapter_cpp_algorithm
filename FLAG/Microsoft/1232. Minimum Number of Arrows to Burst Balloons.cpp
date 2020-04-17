//1232. Minimum Number of Arrows to Burst Balloons
//1. sort with start, for loop from end to start
//2. start ref, if cur end < ref count++, reset ref = cur start


class Solution {
public:
	/**
	 * @param points: a 2D array
	 * @return: the minimum number of arrows that must be shot to burst all balloons
	 */
	int findMinArrowShots(vector<vector<int>>& points) {
		// Write your code here
		class com {
		public:
			bool operator()(const vector<int>& a, const vector<int>& b)
			{
				if (a[0] == b[0]) return a[1] < b[1];
				return a[0] < b[0];
			}
		} cp;
		sort(points.begin(), points.end(), cp);
		int count = 1;
		int ref = points.back()[0];
		for (int i = points.size() - 1; i >= 0; i--)
		{
			if (points[i][1] < ref)
			{
				count++;
				ref = points[i][0];
			}
		}
		return count;
	}
};