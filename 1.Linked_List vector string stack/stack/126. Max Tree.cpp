//126. Max Tree

// devide and conquer partition will get TLE
// 1. use monotonic decreasing stack<TreeNode*>
// 2. while A[i] > stk.top()->val, set min(L,R) as the father of cur node
// 3. after while loop, stk.top()->right = R, stk.push(R)


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
		 * @param A: Given an integer array with no duplicates.
		 * @return: The root of max tree.
		 */
		TreeNode* maxTree(vector<int>& A) {
			// write your code here
			stack<TreeNode*> stk;
			for (int i = 0; i < A.size(); i++)
			{
				TreeNode* right = new TreeNode(A[i]);
				while (!stk.empty() && stk.top()->val < A[i])
				{
					TreeNode* mid = stk.top(); stk.pop();
					TreeNode* left = new TreeNode(INT_MAX);
					if (!stk.empty()) left = stk.top();
					if (left->val < right->val) left->right = mid;
					else right->left = mid;
				}
				if (!stk.empty()) stk.top()->right = right;
				stk.push(right);
			}
			TreeNode* root = nullptr;
			while (!stk.empty())
			{
				root = stk.top(); stk.pop();
			}
			return root;
		}
};