//1197. Find Bottom Left Tree Value
//1. level BFS, if after for loop q.size() == 0 return first value
//1. dfs result(nodeValue, level)

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

	class Solution {
	public:
		/**
		 * @param root: a root of tree
		 * @return: return a integer
		 */
		int findBottomLeftValue(TreeNode* root) {
			// write your code here
			queue<TreeNode*> q;
			q.push(root);
			int cur_depth = 0;
			int res = -1;
			while (!q.empty())
			{
				int q_size = q.size();
				cur_depth++;
				for (int i = 0; i < q_size; i++)
				{
					if (i == 0) res = q.front()->val;
					TreeNode* cur_node = q.front(); q.pop();
					if (cur_node->left) q.push(cur_node->left);
					if (cur_node->right) q.push(cur_node->right);
				}
				if (q.size() == 0) return res;
			}
			return -1;
		}
};