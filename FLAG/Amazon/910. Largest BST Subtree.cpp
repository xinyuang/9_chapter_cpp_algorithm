//910. Largest BST Subtree
//Result store isBST, min, max, ttl_number

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

	class Result {
	public:
		bool isBST;
		int min;
		int max;
		int ttl;
		Result(bool is, int s, int l, int t) :isBST(is), min(s), max(l), ttl(t) {};
};
class Solution {
public:
	/**
	 * @param root: the root
	 * @return: the largest subtree's size which is a Binary Search Tree
	 */
	int largestBSTSubtree(TreeNode* root) {
		// Write your code here
		if (!root) return 0;
		int g_max = 1;
		findLargest(root, g_max);
		return g_max;
	}

	Result findLargest(TreeNode* root, int& g_max)
	{
		if (!root)
		{
			return Result(true, INT_MAX, INT_MIN, 0);
		}
		Result left = findLargest(root->left, g_max);
		Result right = findLargest(root->right, g_max);
		int ttl = left.ttl + right.ttl + 1;
		int c_max = max(root->val, right.max);
		int c_min = min(root->val, left.min);
		bool isBST = left.isBST && right.isBST && (left.max < root->val) && (right.min > root->val);
		if (isBST) g_max = max(g_max, ttl);
		return Result(isBST, c_min, c_max, ttl);
	}
};