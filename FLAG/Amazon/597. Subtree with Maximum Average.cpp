//597. Subtree with Maximum Average
//result store ttl_sum, ttl_number, calculate max_avg

class Result {
public:
	int ttl_number;
	int ttl_sum;
	Result(int n, int s) :ttl_number(n), ttl_sum(s) {}
};

class Solution {
public:
	/**
	 * @param root: the root of binary tree
	 * @return: the root of the maximum average of subtree
	 */
	TreeNode* findSubtree2(TreeNode* root) {
		// write your code here
		if (!root) return nullptr;
		double max_avg = INT_MIN;
		TreeNode* res = nullptr;
		findMxAvTree(root, max_avg, res);
		return res;
	}

	Result findMxAvTree(TreeNode* root, double& max_avg, TreeNode*& res)
	{
		if (!root) return Result(0, 0);
		Result left = findMxAvTree(root->left, max_avg, res);
		Result right = findMxAvTree(root->right, max_avg, res);
		int ttl_number = left.ttl_number + right.ttl_number + 1;
		int ttl_sum = left.ttl_sum + right.ttl_sum + root->val;
		double cur_avg = double(ttl_sum) / double(ttl_number);
		if (max_avg < cur_avg)
		{
			max_avg = cur_avg;
			res = root;
		}
		return Result(ttl_number, ttl_sum);
	}
};