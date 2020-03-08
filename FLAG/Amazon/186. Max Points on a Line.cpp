//186. Max Points on a Line
//1. fix one point, go through other points to get k
//2. mp[k]++res = max(res, mp[k] + 1)

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

	class Solution {
	public:
		/**
		 * @param points: an array of point
		 * @return: An integer
		 */
		int maxPoints(vector<Point>& points) {
			// write your code here
			if (points.size() == 0) return 0;
			int max_count = 1;
			for (int i = 0; i < points.size(); i++)
			{
				unordered_map<double, int> mp;
				int duplica = 0;
				for (int j = 0; j < points.size(); j++)
				{
					if (i == j) continue;
					double k = INT_MAX;
					if (points[i].x != points[j].x)
						k = (float)(points[i].y - points[j].y) / (points[i].x - points[j].x);
					mp[k]++;
				}
				for (auto e : mp)
				{
					max_count = max(max_count, e.second + duplica + 1);
				}
			}
			return max_count;
		}
};