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
	 * @param n: An integer
	 * @param m: An integer
	 * @param operators: an array of point
	 * @return: an integer array
	 */
	vector<int> numIslands2(int n, int m, vector<Point>& operators) {
		// write your code here
		vector<vector<Point>> father(n, vector<Point>(m, Point(-1, -1)));

		vector<bool> islands(n * m, false);
		vector<int> res;
		for (int i = 0; i < operators.size(); i++)
		{
			if (islands[operators[i].x * m + operators[i].y])
			{
				res.push_back(count);
				continue;
			}
			islands[operators[i].x * m + operators[i].y] = true;
			count++;
			int x = operators[i].x;
			int y = operators[i].y;
			father[x][y] = Point(x, y);
			for (int k = 0; k < 4; k++)
			{
				int old_x = x + delta_x[k];
				int old_y = y + delta_y[k];
				if (!is_valid(old_x, old_y, n, m)) continue;
				Point old_point = Point(old_x, old_y);
				if (!islands[old_x * m + old_y]) continue;
				get_union(old_point, operators[i], count, father);
			}
			res.push_back(count);
		}
		return res;
	}

	bool is_valid(int x, int y, int n, int m)
	{
		if (x >= 0 && x < n && y >= 0 && y < m) return true;
		return false;
	}
	void get_union(Point a, Point b, int& count, vector<vector<Point>>& father)
	{
		Point root_a = find(father, a);
		Point root_b = find(father, b);
		if (root_a.x == root_b.x && root_a.y == root_b.y) return;
		father[root_a.x][root_a.y] = root_b;
		count--;
	}

	Point find(vector<vector<Point>>& father, Point a)
	{
		Point root = a;
		vector<Point> path;
		while (root.x != father[root.x][root.y].x || root.y != father[root.x][root.y].y)
		{
			path.push_back(root);
			root = father[root.x][root.y];
		}
		return root;
	}

private:
	int delta_x[4] = { 1,0,-1,0 };
	int delta_y[4] = { 0,1,0,-1 };
	int count = 0;
};