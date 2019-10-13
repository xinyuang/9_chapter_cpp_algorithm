/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

// Binary Tree Zigzag Level Order Traversal
// BFS
// odd  -> queue
// even <- stack
class Solution {
public:
	/**
	 * @param root: A Tree
	 * @return: A list of lists of integer include the zigzag level order traversal of its nodes' values.
	 */
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		// write your code here
		if (!root) return {};
		queue<TreeNode*> q;
		vector<vector<int>> res;
		q.push(root);
		bool odd = true;
		while (!q.empty())
		{
			int q_size = q.size();
			stack<int> even_row;
			queue<int> odd_row;
			for (int i = 0; i < q_size; i++)
			{
				TreeNode* cur = q.front(); q.pop();
				if (cur->left) q.push(cur->left);
				if (cur->right) q.push(cur->right);
				if (odd)
					odd_row.push(cur->val);
				else
					even_row.push(cur->val);
			}
			vector<int> layer;
			if (odd)
			{
				while (!odd_row.empty())
				{
					layer.push_back(odd_row.front()); odd_row.pop();
				}
			}
			else
			{
				while (!even_row.empty())
				{
					layer.push_back(even_row.top()); even_row.pop();
				}
			}
			res.push_back(layer);
			odd = !odd;
		}
		return res;
	}
};