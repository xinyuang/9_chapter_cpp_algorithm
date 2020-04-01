//246. Binary Tree Path Sum II
//1. dfs store path from root to current node
//2. for loop current path, if suffix sum == 0, push_back to res

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
		vector<vector<int>> binaryTreePathSum2(TreeNode* root, int target) {
			// write your code here
			vector<vector<int>> res;
			vector<int> path;
			dfs(root, res, path, 0, target);
			return res;
		}

		void dfs(TreeNode* root, vector<vector<int>>& res, vector<int>& path, int len, int target)
		{
			if (!root) return;
			path.push_back(root->val);
			int left_sum = target;
			for (int i = path.size() - 1; i >= 0; i--)
			{
				left_sum -= path[i];
				if (left_sum == 0)
				{
					vector<int> tar_path;
					for (int j = i; j < path.size(); j++)
					{
						tar_path.push_back(path[j]);
					}
					res.push_back(tar_path);
				}
			}
			dfs(root->right, res, path, len + 1, target);
			dfs(root->left, res, path, len + 1, target);
			path.pop_back();
		}
};