1357. Path Sum II

class Solution {
public:
	/**
	 * @param root: a binary tree
	 * @param sum: the sum
	 * @return: the scheme
	 */
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		// Write your code here.
		if (!root) return {};
		vector<vector<int>> res;
		vector<int> path = { root->val };
		findPath(res, path, root, sum, root->val);
		return res;
	}

	void findPath(vector<vector<int>>& res, vector<int>& path, TreeNode* root, int sum, int acc)
	{
		if (!root->left && !root->right)
		{
			if (acc == sum) res.push_back(path);
			return;
		}
		if (root->left) {
			path.push_back(root->left->val);
			acc += root->left->val;
			findPath(res, path, root->left, sum, acc);
			acc -= root->left->val;
			path.pop_back();
		}
		if (root->right) {
			path.push_back(root->right->val);
			acc += root->right->val;
			findPath(res, path, root->right, sum, acc);
			acc -= root->right->val;
			path.pop_back();
		}
	}
};