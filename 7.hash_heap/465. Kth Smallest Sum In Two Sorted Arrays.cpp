// Kth Smallest Sum In Two Sorted Arrays
//  [2,3,5,7,8]
//   .
//  [3,5,7,9]
//   .                 min_heap  priority_queue<pair<pair<int,int>,int>>   {i,j},sum
// if current element is visited continue
class Solution {
public:
	int kthSum(vector<int> A, vector<int> B, int k) {
		// write your solution here
		typedef pair<pair<int, int>, int> pos;
		struct com {
			bool operator()(pos a, pos b)
			{
				return a.second > b.second;
			}
		};
		priority_queue<pos, vector<pos>, com> q; // min_heap
		int ptr[2] = { 0,0 };
		q.push({ {0,0},A[ptr[0]] + B[ptr[1]] });
		int count = 0;
		vector<vector<int>> visited(A.size(), vector<int>(B.size(), 0));
		visited[0][0] = 1;
		while (!q.empty())
		{
			auto cur = q.top(); q.pop();
			count++;
			if (count == k) return cur.second;
			for (int i = 0; i < 2; i++)
			{
				int new_i = cur.first.first + dx[i];
				int new_j = cur.first.second + dy[i];
				if (!is_valid(new_i, new_j, A, B)) continue;
				if (visited[new_i][new_j]) continue;
				int sum = A[new_i] + B[new_j];
				q.push({ {new_i,new_j},sum });
				visited[new_i][new_j] = 1;
			}
		}
		return -1;
	}
	bool is_valid(int i, int j, vector<int>& A, vector<int>& B)
	{
		if (i >= 0 && i < A.size() && j >= 0 && j < B.size()) return true;
		return false;
	}
private:
	int dx[2] = { 0,1 };
	int dy[2] = { 1,0 };
};