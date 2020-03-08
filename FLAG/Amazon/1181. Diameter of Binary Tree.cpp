//1181. Diameter of Binary Tree
//diameter = left_depth + right_depth

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
		 * @param root: a root of binary tree
		 * @return: return a integer
		 */
		int diameterOfBinaryTree(TreeNode* root) {
			// write your code here
			if (!root) return 0;
			int left = findDiameter(root->left);
			int right = findDiameter(root->right);
			return left + right;
		}

		int findDiameter(TreeNode* root)
		{
			if (!root) return 0;
			int left = findDiameter(root->left);
			int right = findDiameter(root->right);
			return max(left, right) + 1;
		}
};