//1382. Balance a Binary Search Tree
//1.  traverse tree store nodes in array
//2.  construct BST from sorted array


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
	class Solution {
	public:
		TreeNode* balanceBST(TreeNode* root) {
			if (!root) return nullptr;
			vector<int> nodes;
			traverse(root, nodes);
			TreeNode* res = constructBST(nodes, 0, nodes.size() - 1);
			return res;
		}

		TreeNode* constructBST(vector<int>& nodes, int start, int end)
		{
			if (start > end)
				return NULL;

			/* Get the middle element and make it root */
			int mid = (start + end) / 2;
			TreeNode* root = new TreeNode(nodes[mid]);

			/* Recursively construct the left subtree
			and make it left child of root */
			root->left = constructBST(nodes, start,
				mid - 1);

			/* Recursively construct the right subtree
			and make it right child of root */
			root->right = constructBST(nodes, mid + 1, end);

			return root;
		}

		void traverse(TreeNode* root, vector<int>& nodes)
		{
			if (!root) return;
			traverse(root->left, nodes);
			nodes.push_back(root->val);
			traverse(root->right, nodes);
		}
};