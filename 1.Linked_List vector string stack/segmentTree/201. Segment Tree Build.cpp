/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end) {
 *         this->start = start, this->end = end;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
	/*
	 * @param start: start value.
	 * @param end: end value.
	 * @return: The root of Segment Tree.
	 */
	SegmentTreeNode* build(int start, int end) {
		// write your code here
		if (end < start) return nullptr;
		SegmentTreeNode* root = builTree(start, end);
		return root;
	}

	SegmentTreeNode* builTree(int start, int end) {
		if (start == end)
		{
			SegmentTreeNode* newNode = new SegmentTreeNode(start, end);
			return newNode;
		}
		int mid = (end - start) / 2 + start;
		SegmentTreeNode* left = builTree(start, mid);
		SegmentTreeNode* right = builTree(mid + 1, end);
		SegmentTreeNode* node = new SegmentTreeNode(start, end);
		node->left = left;
		node->right = right;
		return node;
	}
};