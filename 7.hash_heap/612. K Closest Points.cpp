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
	 * @param points: a list of points
	 * @param origin: a point
	 * @param k: An integer
	 * @return: the k closest points
	 */

	class compare {
	public:
		Point ori;
		compare(Point origin) : ori(origin) {}
		bool operator() (const Point a, const Point b)
		{
			if (dist(a, ori) == dist(b, ori))
			{
				if (a.x == b.x) return a.y < b.y;
				return a.x < b.x;
			}
			return dist(a, ori) < dist(b, ori);
		}
		int dist(const Point a, const Point b)
		{
			return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
		}
	};
	vector<Point> kClosest(vector<Point>& points, Point& origin, int k) {
		// write your code here
		typedef priority_queue<Point, vector<Point>, compare> heap;
		compare com(origin);
		heap max_heap(com);
		for (Point p : points)
		{
			max_heap.push(p);
			if (max_heap.size() > k) max_heap.pop();
		}
		vector<Point> res;
		while (!max_heap.empty())
		{
			res.push_back(max_heap.top());
			max_heap.pop();
		}
		reverse(res.begin(), res.end());
		return res;
	}


};