//73. Construct Binary Tree from Preorder and Inorder
//divide and conquer
//pre [p_start, p_end]   inorder [i_start,i_end]
//find pre[p_start] position in inorder
//chunck with preorder [p_start+1,position + p_start - i_start]  [position + p_start - i_start + 1, p_end]
//            inorder  [s_start+1,position - 1]   [position + 1, s_end]


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
		 *@param preorder : A list of integers that preorder traversal of a tree
		 *@param inorder : A list of integers that inorder traversal of a tree
		 *@return : Root of a tree
		 */
		TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
			// write your code here
			if (preorder.size() != inorder.size()) return nullptr;
			TreeNode* res = constructTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
			return res;
		}

		TreeNode* constructTree(vector<int>& preorder, int p_start, int p_end, vector<int>& inorder,
			int i_start, int i_end)
		{
			if (p_start > p_end) return nullptr;
			int root_val = preorder[p_start];
			TreeNode* root = new TreeNode(root_val);
			int position = findPosition(inorder, i_start, i_end, root_val);
			root->left = constructTree(preorder, p_start + 1, position + p_start - i_start,
				inorder, i_start, position - 1);
			root->right = constructTree(preorder, position + p_start - i_start + 1, p_end,
				inorder, position + 1, i_end);
			return root;
		}

		int findPosition(vector<int>& inorder, int s, int e, int target)
		{
			for (int i = s; i <= e; i++)
			{
				if (inorder[i] == target)
					return i;
			}
			return -1;
		}
};