475. Binary Tree Maximum Path Sum II
path from root to any node
1. dfs cur, left, right res = max(res, cur + root->left(right)->val)
2. devide and conquer path = max(max(left, right), 0) + root->val;

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
	 * @param root: the root of binary tree.
	 * @return: An integer
	 */
	int maxPathSum2(TreeNode* root) {
		// write your code here
		int res = findMaxPath(root);
		return res;
	}

	int findMaxPath(TreeNode* root)
	{
		if (!root) return 0;
		int left = findMaxPath(root->left);
		int right = findMaxPath(root->right);
		int res = max(0, max(left, right)) + root->val;
		return res;
	}
};

class Solution {
public:
	/**
	 * @param root: the root of binary tree.
	 * @return: An integer
	 */
	int maxPathSum2(TreeNode* root) {
		// write your code here
		int res = INT_MIN;
		getMaxPath(root, res, 0);
		return res;
	}

	void getMaxPath(TreeNode* root, int& res, int path)
	{
		if (!root) return;
		int cur = path + root->val;
		res = max(res, cur);
		getMaxPath(root->left, res, cur);
		getMaxPath(root->right, res, cur);
	}
};
