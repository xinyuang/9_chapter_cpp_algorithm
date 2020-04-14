//865. Smallest Subtree with all the Deepest Nodes

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Result {
public:
	TreeNode* subtree;
	int level;
	Result(TreeNode* s, int l)
	{
		subtree = s;
		level = l;
	}
};
class Solution {
public:
	TreeNode* subtreeWithAllDeepest(TreeNode* root) {
		Result res = findSubtree(root);
		return res.subtree;
	}

	Result findSubtree(TreeNode* cur)
	{
		if (!cur) return Result(nullptr, 0);
		Result l = findSubtree(cur->left);
		Result r = findSubtree(cur->right);
		if (l.level == r.level) return Result(cur, l.level + 1);
		if (l.level > r.level)
		{
			return Result(l.subtree, l.level + 1);
		}
		else
		{
			return Result(r.subtree, r.level + 1);
		}
	}
};