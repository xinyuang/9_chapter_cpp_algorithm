//86. Binary Search Tree Iterator
//1. stack, dummy->right = root
//2. next is stk top, pop top, move to right, push left to the end

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
 * Example of iterate a tree:
 * BSTIterator iterator = BSTIterator(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */


class BSTIterator {
private:
	stack<TreeNode*> stk;
public:
	/*
	* @param root: The root of binary tree.
	*/BSTIterator(TreeNode* root) {
	// do intialization if necessary
	while (!stk.empty()) stk.pop();
	TreeNode* dummy = new TreeNode(0);
	dummy->right = root;
	stk.push(dummy);
	next();
}

		/*
		* @return: True if there has next node, or false
		*/
		bool hasNext() {
			// write your code here
			if (stk.size() > 0) return true;
			return false;
		}

		/*
		* @return: return next node
		*/
		TreeNode* next() {
			// write your code here
			TreeNode* cur = stk.top(); stk.pop();
			TreeNode* next = cur->right;
			if (next)
			{
				while (next)
				{
					stk.push(next);
					next = next->left;
				}
			}
			return cur;
		}
};