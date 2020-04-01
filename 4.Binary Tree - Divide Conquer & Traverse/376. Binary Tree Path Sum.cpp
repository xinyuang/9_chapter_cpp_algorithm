//376. Binary Tree Path Sum

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
		/*
		 * @param root: the root of binary tree
		 * @param target: An integer
		 * @return: all valid paths
		 */
		vector<vector<int>> binaryTreePathSum(TreeNode* root, int target) {
			// write your code here
			vector<vector<int>> res;
			vector<int> path;
			getPath(res, path, root, target, 0);
			return res;
		}

		void getPath(vector<vector<int>>& res, vector<int>& path, TreeNode* root, int target, int cur_sum)
		{
			if (!root) return;
			path.push_back(root->val);
			cur_sum += root->val;
			if (cur_sum == target && !root->left && !root->right)
			{
				res.push_back(path);
			}
			getPath(res, path, root->left, target, cur_sum);
			getPath(res, path, root->right, target, cur_sum);
			path.pop_back();
		}
};