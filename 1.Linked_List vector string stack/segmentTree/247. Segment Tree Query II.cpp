/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, count;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int count) {
 *         this->start = start;
 *         this->end = end;
 *         this->count = count;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
	/*
	 * @param root: The root of segment tree.
	 * @param start: start value.
	 * @param end: end value.
	 * @return: The count number in the interval [start, end]
	 */
	int query(SegmentTreeNode* root, int start, int end) {
		// write your code here
		if (!root) return 0;
		if (root->start >= start && root->end <= end) return root->count;
		int mid = (root->start + root->end) / 2;
		int left = 0, right = 0;
		if (start <= mid)
		{
			left = query(root->left, start, min(end, mid));
		}
		if (end > mid)
		{
			right = query(root->right, max(start, mid + 1), end);
		}
		return left + right;
	}
};