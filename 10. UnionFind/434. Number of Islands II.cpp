//434. Number of Islands II
//
//1. if already a island, res.push_back(count) father[x* col + y]
//2. if new island, set it as father, count++, for loop neighbor, add edge.
//3. only when add edge, island merges, count--


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
private:
	vector<int> father;
	int col;
	int count;
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };
public:
	/**
	 * @param n: An integer
	 * @param m: An integer
	 * @param operators: an array of point
	 * @return: an integer array
	 */
	vector<int> numIslands2(int n, int m, vector<Point>& operators) {
		// write your code here
		count = 0;
		col = m;
		father = vector<int>(m * n, 0);
		vector<vector<int>> island(n, vector<int>(m, 0));
		vector<int> res;
		for (int i = 0; i < operators.size(); i++)
		{
			int x = operators[i].x;
			int y = operators[i].y;
			if (island[x][y] == 1) {
				res.push_back(count);
				continue;
			}
			island[x][y] = 1;
			father[x * m + y] = x * m + y;
			count++;
			for (int k = 0; k < 4; k++)
			{
				int new_x = x + dx[k];
				int new_y = y + dy[k];
				if (!is_valid(new_x, new_y, n, m)) continue;
				if (island[new_x][new_y] == 0) continue;
				addEdge(new_x, new_y, x, y);
			}
			res.push_back(count);
		}
		return res;
	}

	void addEdge(int i, int j, int x, int y)
	{
		int rootA = findRoot(i, j);
		int rootB = findRoot(x, y);
		if (rootA != rootB)
		{
			father[rootB] = rootA;
			count--;
		}
	}

	bool is_valid(int x, int y, int n, int m)
	{
		if (x >= 0 && x < n && y >= 0 && y < m) return true;
		return false;
	}

	int findRoot(int x, int y)
	{
		int cur = x * col + y;
		while (father[cur] != cur)
		{
			cur = father[cur];
		}
		return cur;
	}
};