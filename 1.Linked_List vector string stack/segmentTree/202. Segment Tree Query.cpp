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

// 202. Segment Tree Query
//                          [0, 3, max = 4]
//                               / \
//                  [0, 1, max = 4][2, 3, max = 3]
//                        / \              / \
//       [0, 0, max = 1][1, 1, max = 4][2, 2, max = 2], [3, 3, max = 3]
//              [start,end]  
//   max([start,min(end,mid)],[max(mid+1,start),end])
class Solution {
public:
	/**
	 * @param root: The root of segment tree.
	 * @param start: start value.
	 * @param end: end value.
	 * @return: The maximum number in the interval [start, end]
	 */
	int query(SegmentTreeNode* root, int start, int end) {
		// write your code here
		if (root->start >= start && root->end <= end)
		{
			return root->max;
		}
		int mid = (root->end + root->start) / 2;
		int left = INT_MIN, right = INT_MIN;
		if (start <= mid)
		{
			left = query(root->left, start, min(end, mid));
		}
		if (end > mid)
		{
			right = query(root->right, max(mid + 1, start), end);
		}
		int res = max(left, right);
		return res;
	}
};