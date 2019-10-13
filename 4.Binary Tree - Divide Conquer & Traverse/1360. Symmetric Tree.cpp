// Symmetric Tree

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

//          a
//         / \
//        b   c              divide and conquer
//       /\   /\
//      d  e  e f
class Solution {
public:
	/**
	 * @param root: root of the given tree
	 * @return: whether it is a mirror of itself
	 */
	bool isSymmetric(TreeNode* root) {
		// Write your code here
		return !root || isSym(root->left, root->right);
	}

	bool isSym(TreeNode* leftNode, TreeNode* rightNode)
	{
		if (!leftNode || !rightNode) return !leftNode && !rightNode;
		if (leftNode->val != rightNode->val) return false;
		return isSym(leftNode->left, rightNode->right) && isSym(leftNode->right, rightNode->left);
	}
};


// inorder traverse [1,2,3,2,1]
// check palindrome 
class Solution {
public:
	/**
	 * @param root: root of the given tree
	 * @return: whether it is a mirror of itself
	 */
	bool isSymmetric(TreeNode* root) {
		// Write your code here
		vector<int> res;
		traverse(root, res);
		int left = 0, right = res.size() - 1;
		while (left < right)
		{
			if (res[left] != res[right]) return false;
			left++; right--;
		}
		return true;
	}

	void traverse(TreeNode* root, vector<int>& res)
	{
		if (!root) return;
		traverse(root->left, res);
		res.push_back(root->val);
		traverse(root->right, res);
	}

};

