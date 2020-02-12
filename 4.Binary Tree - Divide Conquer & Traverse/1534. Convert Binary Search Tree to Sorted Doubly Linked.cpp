//  inorder traverse tree
//  doubly linked list (start,end)

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
	 * @param root: root of a tree
	 * @return: head node of a doubly linked list
	 */
	TreeNode* treeToDoublyList(TreeNode* root) {
		// Write your code here.
		if (!root) return nullptr;
		TreeNode* head = nullptr;
		TreeNode* tail = nullptr;
		toList(root, &head, &tail);
		tail->right = head;
		head->left = tail;
		return head;
	}

	void toList(TreeNode* root, TreeNode** head, TreeNode** tail)
	{
		if (!root) return;

		toList(root->left, head, tail);
		if (!*head)
		{
			*head = root;
			*tail = root;
		}
		else
		{
			(*tail)->right = root;
			root->left = *tail;
			*tail = root;
		}
		toList(root->right, head, tail);
	}
};