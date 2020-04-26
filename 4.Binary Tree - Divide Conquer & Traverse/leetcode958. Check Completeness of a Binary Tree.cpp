// Check If Binary Tree Is Completed
//class TreeNode {
// public:
//  int value;
//  TreeNode* left;
//  TreeNode* right;
//  TreeNode(int v) : value(v), left(NULL), right(NULL) {}
//};
class Solution {
public:
	bool isCompleted(TreeNode* root) {
		// write your solution here
		queue<TreeNode*> q;
		q.push(root);
		bool findend = false;
		while (!q.empty())
		{
			int q_size = q.size();
			for (int i = 0; i < q_size; i++)
			{
				TreeNode* cur = q.front(); q.pop();
				if (!cur)
				{
					findend = true;
					continue;
				}
				else if (findend) return false;
				q.push(cur->left);
				q.push(cur->right);
			}
		}
		return true;
	}
};

// if the tree level is too high, cannot use this method to get idx (i.e. 2^100)
class Solution {
private:
	long max_idx = 0;
	long count = 0;
public:
	bool isCompleteTree(TreeNode* root) {
		dfs(root, 1);
		return max_idx == count;
	}

	void dfs(TreeNode* root, long idx)
	{
		if (!root) return;
		count++;
		cout << idx << endl;
		max_idx = max(max_idx, idx);
		dfs(root->left, 2 * idx);
		dfs(root->right, 2 * idx + 1);
	}
};
