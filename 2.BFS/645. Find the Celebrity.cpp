// Find the Celebrity

// if candidate knows someone, he cannot be celebrity
// candidate move to the next one (i >= candidate, because previous one is not celebrity)
//     0,1,2,3,4
//     1 . . 
//     2   . .
//     3,    .
bool knows(int a, int b);

class Solution {
public:
	/**
	 * @param n a party with n people
	 * @return the celebrity's label or -1
	 */
	int findCelebrity(int n) {
		// Write your code here
		int candidate = 0;
		for (int i = 1; i < n; i++)
		{
			if (knows(candidate, i))
			{
				candidate = i;
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (i != candidate && knows(candidate, i)) return -1;
			if (i != candidate && !knows(i, candidate)) return -1;
		}
		return candidate;
	}
};


// matrix[i][j] means people i known people j
// check indegree == ttl_people - 1 && graph.size() == 1 (himself)
// Brutal solution n^2
class Solution {
public:
	int celebrity(vector<vector<int>> matrix) {
		// write your solution here
		int m = matrix.size();
		int n = matrix[0].size();
		unordered_map<int, int> indegree; // idx,   count
		unordered_map<int, unordered_set<int>> graph;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i != j && matrix[i][j] == 0) continue;
				indegree[j]++;
				graph[i].insert(j);
				if (!graph.count(j)) graph[j] = {};
			}
		}
		int ttl_people = graph.size();
		for (int i = 0; i < indegree.size(); i++)
		{
			if (indegree[i] == ttl_people && graph[i].size() == 1) return i;
		}
		return -1;
	}
};

// if candidate knows someone, he cannot be celebrity
// candidate move to the next one (i >= candidate, because previous one is not celebrity)
//     0,1,2,3,4
//     1 . . 
//     2   . .
//     3,    .
class Solution {
public:
	int celebrity(vector<vector<int>> matrix) {
		// write your solution here
		int m = matrix.size();
		int n = matrix[0].size();
		if (m == 0 || n == 0) return -1;
		int candidate = 0;
		for (int i = 1; i < m; i++)
		{
			if (matrix[candidate][i])
			{
				candidate = i;
			}
		}
		for (int i = 0; i < m; i++)
		{
			if (i != candidate && matrix[candidate][i]) return -1;
			if (i != candidate && !matrix[i][candidate]) return -1;
		}
		return candidate;
	}
};