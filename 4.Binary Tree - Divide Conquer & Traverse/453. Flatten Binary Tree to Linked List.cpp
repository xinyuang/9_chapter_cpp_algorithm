453. Flatten Binary Tree to Linked List
1. divide and conquer, flatten left, right, then connect root->left->right
1. while loop, find left tree most right, integrate left tree to right tree, root = root->right

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
		* @param root: a TreeNode, the root of the binary tree
		* @return: nothing
		*/
	void flatten(TreeNode* root) {
		// write your code here
		TreeNode* cur = root;
		while (root)
		{
			cur = root->left;
			if (cur)
			{
				while (cur->right) cur = cur->right;
				cur->right = root->right;
				root->right = root->left;
			}
			root->left = nullptr;
			root = root->right;
		}
	}
};

class Solution {
public:
	/**
	 * @param root: a TreeNode, the root of the binary tree
	 * @return: nothing
	 */
	void flatten(TreeNode* root) {
		// write your code here
		Traverse(root);
	}

	TreeNode* Traverse(TreeNode* root)
	{
		if (!root) return nullptr;
		if (!root->left && !root->right) return root;
		TreeNode* end = Traverse(root->left);
		TreeNode* rightEnd = Traverse(root->right);
		if (end)
		{
			end->right = root->right;
			root->right = root->left;
			root->left = nullptr;
		}
		if (!rightEnd) return end;
		return rightEnd;
	}
};