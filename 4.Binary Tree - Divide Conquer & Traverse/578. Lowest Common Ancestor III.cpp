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
	/*
	 * @param root: The root of the binary tree.
	 * @param A: A TreeNode
	 * @param B: A TreeNode
	 * @return: Return the LCA of the two nodes.
	 */
	class Result {
	public:
		bool findA;
		bool findB;
		Result(bool a, bool b) : findA(a), findB(b) {}
	};
	TreeNode* lowestCommonAncestor3(TreeNode* root, TreeNode* A, TreeNode* B) {
		// write your code here
		TreeNode* lca = nullptr;
		findLCA(root, A, B, lca);
		return lca;
	}

	Result findLCA(TreeNode* root, TreeNode* A, TreeNode* B, TreeNode*& lca)
	{
		if (!root) return Result(false, false);

		Result left = findLCA(root->left, A, B, lca);
		Result right = findLCA(root->right, A, B, lca);
		bool findA = false;
		bool findB = false;
		if (left.findA || right.findA || root == A) findA = true;
		if (left.findB || right.findB || root == B) findB = true;
		if (findA && findB)
		{
			if (!lca) lca = root;
		}
		return Result(findA, findB);
	}
};


/**
 * Definition of ParentTreeNode:
 * class ParentTreeNode {
 * public:
 *     int val;
 *     ParentTreeNode *parent, *left, *right;
 * }
 */


//LCA with parent


class Solution {
public:
	/*
	 * @param root: The root of the tree
	 * @param A: node in the tree
	 * @param B: node in the tree
	 * @return: The lowest common ancestor of A and B
	 */
	ParentTreeNode* lowestCommonAncestorII(ParentTreeNode* root, ParentTreeNode* A, ParentTreeNode* B) {
		// write your code here
		queue<ParentTreeNode*> qa;
		queue<ParentTreeNode*> qb;
		ParentTreeNode* cur_a = A;
		while (cur_a != root)
		{
			qa.push(cur_a);
			cur_a = cur_a->parent;
		}
		qa.push(root);
		ParentTreeNode* cur_b = B;
		while (cur_b != root)
		{
			qb.push(cur_b);
			cur_b = cur_b->parent;
		}
		qb.push(root);
		int dif = abs(qa.size() - qb.size());
		while (qa.size() > qb.size())qa.pop();
		while (qb.size() > qa.size())qb.pop();
		while (qa.front() != qb.front())
		{
			qa.pop();
			qb.pop();
		}
		ParentTreeNode* lca = qa.front();
		return lca;
	}
};


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
	/*
	 * @param root: The root of the binary search tree.
	 * @param A: A TreeNode in a Binary.
	 * @param B: A TreeNode in a Binary.
	 * @return: Return the least common ancestor(LCA) of the two nodes.
	 */
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* A, TreeNode* B) {
		// write your code here
		if (!root) return nullptr;
		if (root == A || root == B) return root;
		TreeNode* left = lowestCommonAncestor(root->left, A, B);
		TreeNode* right = lowestCommonAncestor(root->right, A, B);
		if (left && right)  return root;
		if (left) return left;
		if (right) return right;
		return nullptr;
	}
};