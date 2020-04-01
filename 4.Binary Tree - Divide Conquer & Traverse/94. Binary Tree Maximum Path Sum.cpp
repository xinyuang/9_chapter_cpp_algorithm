//94. Binary Tree Maximum Path Sum
//path from any node to any node
//1. Result max single path, full path
//2. single = max(0, max(left.single, right.single)) + root->val
//3. full = max(max(left.full, right.full), max(0, left.single) + max(0, right.single) + root.val)

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
		 * @param root: The root of binary tree.
		 * @return: An integer
		 */
		int maxPathSum(TreeNode* root) {
			// write your code here
			vector<int> res = findPath(root);  // 0 is max_sum, 1 is presum
			return max(res[0], res[1]);
		}

		vector<int> findPath(TreeNode* root)
		{
			if (!root) return { INT_MIN,INT_MIN };
			vector<int> left = findPath(root->left);
			vector<int> right = findPath(root->right);
			int cur_path = max(0, left[1]) + max(0, right[1]) + root->val;
			int max_sum = max(cur_path, max(left[0], right[0]));
			int presum = max(0, max(left[1], right[1])) + root->val;
			return { max_sum, presum };
		}
};