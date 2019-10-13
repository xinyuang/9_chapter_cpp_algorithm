
/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

// Build SegmentTree
// Divide and Conquer
//Input: [3, 2, 1, 4]
//	Explanation :
//	The segment tree will be
//	      [0, 3](max = 4)
//	        / \
//	    [0, 1][2, 3]
//	(max = 3)       (max = 4)
//	   / \           / \
//	[0, 0][1, 1]  [2, 2][3, 3]
//(max = 3)(max = 2)(max = 1)(max = 4)
class Solution {
public:
	/**
	 * @param A: a list of integer
	 * @return: The root of Segment Tree
	 */
	SegmentTreeNode* build(vector<int>& A) {
		// write your code here
		int n = A.size();
		if (n == 0) return nullptr;
		SegmentTreeNode* root = buildTree(A, 0, n - 1);
		return root;
	}

	SegmentTreeNode* buildTree(vector<int>& A, int start, int end)
	{
		if (start == end)
		{
			SegmentTreeNode* newNode = new SegmentTreeNode(start, end, A[start]);
			return newNode;
		}
		int mid = (end - start) / 2 + start;
		SegmentTreeNode* left = buildTree(A, start, mid);
		SegmentTreeNode* right = buildTree(A, mid + 1, end);
		int max_value = max(left->max, right->max);
		SegmentTreeNode* node = new SegmentTreeNode(start, end, max_value);
		node->left = left;
		node->right = right;
		return node;
	}
};