//1106. Maximum Binary Tree
//divide and conquer, find max_id, build(start, max_idx - 1) build(max_idx + 1, end) return root

class Solution {
public:
	/**
	 * @param nums: an array
	 * @return: the maximum tree
	 */
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		// Write your code here
		TreeNode* root = buildTree(nums, 0, nums.size() - 1);
		return root;
	}

	TreeNode* buildTree(vector<int>& nums, int start, int end)
	{
		if (start > end) return nullptr;
		int max_idx = start;
		int max_v = nums[start];
		for (int i = start; i <= end; i++)
		{
			if (max_v < nums[i])
			{
				max_v = nums[i];
				max_idx = i;
			}
		}
		TreeNode* root = new TreeNode(max_v);
		TreeNode* left = buildTree(nums, start, max_idx - 1);
		TreeNode* right = buildTree(nums, max_idx + 1, end);
		root->left = left;
		root->right = right;
		return root;
	}
};