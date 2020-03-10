//1418. Path With Maximum Minimum Value
//1. max_heap store{ {x,y},value }
//2. BFS, mark visited, min_path = min(min_path, cur_value)  till R - 1, C - 1 break,
//3. we can ensure branch path point always larger than min(main_path)

class Solution {
private:
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };
public:
	/**
	 * @param A: a List[List[int]]
	 * @return: Return the maximum score of a path
	 */
	int maximumMinimumPath(vector<vector<int>>& A) {
		// Write your code here
		if (A.size() == 0 || A[0].size() == 0) return -1;
		typedef pair<pair<int, int>, int> pos; // {{x,y}, value}
		class cmp {
		public:
			bool operator()(const pos& a, const pos& b)
			{
				return a.second < b.second;
			}
		};
		priority_queue<pos, vector<pos>, cmp> max_heap;
		vector<vector<int>> visited(A.size(), vector<int>(A[0].size(), 0));
		int path_min = INT_MAX;
		max_heap.push({ {0,0},A[0][0] });
		visited[0][0] = 1;
		while (!max_heap.empty())
		{
			pos cur = max_heap.top(); max_heap.pop();
			int x = cur.first.first;
			int y = cur.first.second;
			path_min = min(path_min, cur.second);
			if (x == A.size() - 1 && y == A[0].size() - 1) break;
			for (int i = 0; i < 4; i++)
			{
				int new_x = x + dx[i];
				int new_y = y + dy[i];
				if (!is_valid(new_x, new_y, A)) continue;
				if (visited[new_x][new_y]) continue;
				max_heap.push({ {new_x, new_y}, A[new_x][new_y] });
				visited[new_x][new_y] = 1;
			}
		}
		return path_min;
	}

	bool is_valid(int x, int y, vector<vector<int>>& A)
	{
		if (x >= 0 && x < A.size() && y >= 0 && y < A[0].size()) return true;
		return false;
	}
};