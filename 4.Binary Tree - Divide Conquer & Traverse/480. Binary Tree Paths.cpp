// Binary Tree Paths

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

// DFS
class Solution {
public:
	/**
	 * @param root: the root of the binary tree
	 * @return: all root-to-leaf paths
	 */
	vector<string> binaryTreePaths(TreeNode* root) {
		// write your code here
		if (!root) return {};
		vector<string> res;
		vector<int> path = { root->val };
		backtrack(res, path, root);
		return res;
	}

	void backtrack(vector<string>& res, vector<int>& path, TreeNode* root)
	{
		if (!root->right && !root->left)
		{
			string ans = toString(path);
			res.push_back(ans);
			return;
		}
		if (root->left)
		{
			path.push_back(root->left->val);
			backtrack(res, path, root->left);
			path.pop_back();
		}
		if (root->right)
		{
			path.push_back(root->right->val);
			backtrack(res, path, root->right);
			path.pop_back();
		}
	}

	string toString(vector<int>& path)
	{
		string res;
		for (int i = 0; i < path.size(); i++)
		{
			res += to_string(path[i]);
			if (i != path.size() - 1) res += "->";
		}
		return res;
	}
};

// Devide and Conquer
class Solution {
public:
	/**
	 * @param root: the root of the binary tree
	 * @return: all root-to-leaf paths
	 */
	vector<string> binaryTreePaths(TreeNode* root) {
		// write your code here
		vector<string> res;
		res = searchAllPath(root);
		vector<string> ret;
		for (string str : res)
		{
			str.erase(0, 2);
			ret.push_back(str);
		}
		return ret;
	}

	vector<string> searchAllPath(TreeNode* root)
	{
		if (!root) return {};
		if (!root->left && !root->right)
		{
			string cur_path = to_string(root->val);
			return { "->" + cur_path };
		}
		vector<string> left = searchAllPath(root->left);
		vector<string> right = searchAllPath(root->right);
		vector<string> res;
		string cur_str = "->" + to_string(root->val);
		for (string str : left)
		{
			res.push_back(cur_str + str);
		}
		for (string str : right)
		{
			res.push_back(cur_str + str);
		}
		return res;
	}
};