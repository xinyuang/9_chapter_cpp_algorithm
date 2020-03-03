//86. Binary Search Tree Iterator
//1. stack, dummy->right = root
//2. next is stk top, pop top, move to right, push left to the end

class BSTIterator {
private:
	stack<TreeNode*> stk;
public:
	/*
	* @param root: The root of binary tree.
	*/BSTIterator(TreeNode* root) {
	// do intialization if necessary
	TreeNode* dummy = new TreeNode(0);
	dummy->right = root;
	while (!stk.empty()) stk.pop();
	stk.push(dummy);
	this->next();
}

	  /*
	   * @return: True if there has next node, or false
	   */
	  bool hasNext() {
		  // write your code here
		  return !stk.empty();
	  }

	  /*
	   * @return: return next node
	   */
	  TreeNode* next() {
		  // write your code here
		  TreeNode* res = stk.top(); stk.pop();
		  TreeNode* rightTree = res->right;
		  if (rightTree)
		  {
			  TreeNode* cur = rightTree;
			  while (cur)
			  {
				  stk.push(cur);
				  cur = cur->left;
			  }
		  }
		  return res;
	  }
};