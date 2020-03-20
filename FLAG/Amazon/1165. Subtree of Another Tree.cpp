//1165. Subtree of Another Tree
//1. divide and conquer
//2. isSameTree(root) || containSubtree(root->left, tar) || containSubtree(root->right, tar)
//3. if !root return tar == nullptr

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
		 * @param s: the s' root
		 * @param t: the t' root
		 * @return: whether tree t has exactly the same structure and node values with a subtree of s
		 */
		bool isSubtree(TreeNode* s, TreeNode* t) {
			// Write your code here
			bool res = findSame(s, t);
			return res;
		}

		bool curSame(TreeNode* s, TreeNode* t)
		{
			if (!s) return t == nullptr;
			if (!t || s->val != t->val) return false;
			bool left = curSame(s->left, t->left);
			bool right = curSame(s->right, t->right);
			return left && right;
		}

		bool findSame(TreeNode* s, TreeNode* t)
		{
			if (s == nullptr) return t == nullptr;
			bool cur = curSame(s, t);
			bool findleft = findSame(s->left, t);
			bool findright = findSame(s->right, t);
			if (findleft || findright || cur) return true;
			return false;
		}

};