// Kth Smallest Number in Sorted Matrix

// min_heap right, down
// the Kth in queue is the Kth smallest
// record visited element
class Solution {
public:
	/**
	 * @param matrix: a matrix of integers
	 * @param k: An integer
	 * @return: the kth smallest number in the matrix
	 */
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		// write your code here
		if (matrix.size() == 0 || matrix[0].size() == 0) return -1;
		if (matrix.size() * matrix[0].size() < k) return -1;
		// Point - value
		typedef pair<pair<int, int>, int> Point;
		class compare {
		public:
			bool operator()(Point a, Point b)
			{
				return a.second > b.second;
			}
		};
		priority_queue<Point, vector<Point>, compare> min_heap;
		min_heap.push(make_pair(make_pair(0, 0), matrix[0][0]));
		vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
		visited[0][0] = true;
		int count = 0;
		while (!min_heap.empty())
		{
			Point cur = min_heap.top();
			min_heap.pop();
			count++;
			int x = cur.first.first;
			int y = cur.first.second;
			int cur_v = cur.second;
			if (count == k) return cur_v;

			for (int i = 0; i < 2; i++)
			{
				int new_x = x + delta_x[i];
				int new_y = y + delta_y[i];
				if (!is_valid(new_x, new_y, matrix) || visited[new_x][new_y]) continue;
				min_heap.push(make_pair(make_pair(new_x, new_y), matrix[new_x][new_y]));
				visited[new_x][new_y] = true;
			}
		}
		return -1;
	}

	bool is_valid(int x, int y, vector<vector<int>>& matrix)
	{
		if (x >= 0 && y >= 0 && x < matrix.size() && y < matrix[0].size()) return true;
		return false;
	}
private:
	int delta_x[2] = { 1,0 };
	int delta_y[2] = { 0,1 };
};

// Binary Search
// small--------
//    |        |
//    |        |
//     --------max    find(mid,matrix)  find number (range) of ele smaller than mid
//                       if  range < k, left = mid
class Solution {
public:
	/**
	 * @param matrix: a matrix of integers
	 * @param k: An integer
	 * @return: the kth smallest number in the matrix
	 */
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		// write your code here
		if (matrix.size() == 0 || matrix[0].size() == 0) return -1;
		if (matrix.size() * matrix[0].size() < k) return -1;
		int left = matrix[0][0];
		int right = matrix[matrix.size() - 1][matrix[0].size() - 1];
		while (left + 1 < right)
		{
			int mid = (right - left) / 2 + left;
			int range = find(mid, matrix);
			if (range < k) left = mid;
			else right = mid;
		}
		int left_count = find(left, matrix);
		if (find(left, matrix) + 1 <= k) return left;
		return right;
	}

	int find(int target, vector<vector<int>>& matrix)
	{
		int count = 0;
		int m = matrix.size(), n = matrix[0].size();
		int row = m - 1, col = 0;
		while (row >= 0 && col < n)
		{
			if (matrix[row][col] < target)
			{
				count += row + 1;
				col++;
			}
			else
			{
				row--;
			}
		}
		return count;
	}
};