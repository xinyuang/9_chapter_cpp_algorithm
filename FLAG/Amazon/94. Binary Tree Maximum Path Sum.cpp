//94. Binary Tree Maximum Path Sum
//
//path from any node to any node
//1. Result max single path, full path
//2. single = max(0, max(left.single, right.single)) + root->val
//3. full = max(max(left.full, right.full), max(0, left.single) + max(0, right.single) + root.val)

class Solution {
public:
	/**
	 * @param root: The root of binary tree.
	 * @return: An integer
	 */
	int maxPathSum(TreeNode* root) {
		// write your code here
		if (!root) return 0;
		vector<int> res = findMax(root);
		int max_res = max(res[0], res[1]);
		return max_res;
	}

	vector<int> findMax(TreeNode* root)
	{
		if (!root) return { 0,INT_MIN };
		vector<int> left = findMax(root->left);
		vector<int> right = findMax(root->right);
		int cur_path = max(0, max(left[0], right[0])) + root->val;
		int prev_max_path = max(max(left[1], right[1]), max(0, left[0]) + max(0, right[0]) + root->val);
		return { cur_path,prev_max_path };
	}
};