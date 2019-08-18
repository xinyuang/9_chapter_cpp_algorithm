class Solution {
public:
	/**
	 * @param matrix: a matrix of integers
	 * @param k: An integer
	 * @return: the kth smallest number in the matrix
	 */
	class compare {
	public:
		bool operator() (const pair<int, pair<int, int>> a, const pair<int, pair<int, int>> b)
		{
			return b.first < a.first;
		}
	};
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		// write your code here
		if (matrix.size() == 0 || matrix[0].size() == 0) return NULL;
		if (k > matrix.size() * matrix[0].size()) return NULL;
		typedef pair<int, int> Point;
		typedef pair<int, Point> VPos;
		typedef priority_queue<VPos, vector<VPos>, compare> min_heap;
		min_heap q;
		q.push(make_pair(matrix[0][0], make_pair(0, 0)));
		int res = INT_MAX;
		unordered_set<int> visited;
		visited.insert(0);
		for (int i = 0; i < k; i++)
		{
			VPos cur = q.top();
			int x = cur.second.first;
			int y = cur.second.second;
			res = matrix[x][y];
			q.pop();
			if (x + 1 < matrix.size() && !visited.count((x + 1) * matrix[0].size() + y))
			{
				q.push(make_pair(matrix[x + 1][y], make_pair(x + 1, y)));
				visited.insert((x + 1) * matrix[0].size() + y);
			}
			if (y + 1 < matrix[0].size() && !visited.count(x * matrix[0].size() + y + 1))
			{
				q.push(VPos(matrix[x][y + 1], make_pair(x, y + 1)));
				visited.insert(x * matrix[0].size() + y + 1);
			}
		}
		return res;
	}
};