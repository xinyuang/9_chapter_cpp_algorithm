472. Binary Tree Path Sum III

/**
 * Definition of ParentTreeNode:
 * class ParentTreeNode {
 * public:
 *     int val;
 *     ParentTreeNode *parent, *left, *right;
 * }
 */


	class Solution {
	public:
		/*
		 * @param root: the root of binary tree
		 * @param target: An integer
		 * @return: all valid paths
		 */
		vector<vector<int>> binaryTreePathSum3(ParentTreeNode* root, int target) {
			// write your code here
			vector<vector<int>> res;
			traverse(root, target, res);
			return res;
		}

		void traverse(ParentTreeNode* root, int target, vector<vector<int>>& res)
		{
			if (!root) return;
			vector<int> path;
			findPath(root, nullptr, path, target, res);
			traverse(root->left, target, res);
			traverse(root->right, target, res);
		}

		void findPath(ParentTreeNode* cur, ParentTreeNode* prev, vector<int>& path,
			int cur_sum, vector<vector<int>>& res)
		{
			if (!cur) return;
			int left_sum = cur_sum;
			left_sum -= cur->val;
			path.push_back(cur->val);
			if (left_sum == 0)
			{
				res.push_back(path);
			}
			if (cur->parent != prev) findPath(cur->parent, cur, path, left_sum, res);
			if (cur->left != prev) findPath(cur->left, cur, path, left_sum, res);
			if (cur->right != prev) findPath(cur->right, cur, path, left_sum, res);
			path.pop_back();
		}
};
