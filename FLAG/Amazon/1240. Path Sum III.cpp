//1240. Path Sum III
//1. #left - non - root - sum + #right - non - root - sum + #root - sum
//2. #left - root - sum + #right - root - sum + (root->val == sum ? 1 : 0)

class Solution {
public:
	/**
	 * @param root:
	 * @param sum:
	 * @return: the num of sum path
	 */
	int pathSum(TreeNode* root, int sum) {
		// write your code here
		if (!root) return 0;
		return pathSum(root->left, sum) + pathSum(root->right, sum) + rootPath(root, sum);
	}

	int rootPath(TreeNode* root, int sum)
	{
		if (!root) return 0;
		int res = 0;
		if (sum == root->val) res++;
		int left = rootPath(root->left, sum - root->val);
		int right = rootPath(root->right, sum - root->val);
		return left + right + res;
	}
};