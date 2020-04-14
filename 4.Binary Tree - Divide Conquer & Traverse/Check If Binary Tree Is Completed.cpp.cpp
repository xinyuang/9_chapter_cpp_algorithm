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
