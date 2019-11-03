// O(NlogK)
// Merge K Sorted Lists
// merge sort
/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
	/**
	 * @param lists: a list of ListNode
	 * @return: The head of one sorted list.
	 */
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		// write your code here
		ListNode* res = mergeSort(lists, 0, lists.size() - 1);
		return res;
	}

	ListNode* mergeSort(vector<ListNode*> lists, int start, int end)
	{
		if (start >= end) return lists[start];
		int mid = (end - start) / 2 + start;
		ListNode* left = mergeSort(lists, start, mid);
		ListNode* right = mergeSort(lists, mid + 1, end);
		ListNode* res = merge(left, right);
		return res;
	}

	ListNode* merge(ListNode* left, ListNode* right)
	{
		ListNode* dummy = new ListNode(0);
		ListNode* cur = dummy;
		while (left && right)
		{
			if (left->val < right->val)
			{
				cur->next = left;
				left = left->next;
			}
			else
			{
				cur->next = right;
				right = right->next;
			}
			cur = cur->next;
		}

		while (left)
		{
			cur->next = left;
			left = left->next;
			cur = cur->next;
		}

		while (right)
		{
			cur->next = right;
			right = right->next;
			cur = cur->next;
		}
		return dummy->next;
	}
};


// priority_queue
/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
	/**
	 * @param lists: a list of ListNode
	 * @return: The head of one sorted list.
	 */
	struct Comparator {
		bool operator() (ListNode* left, ListNode* right) const {
			return left->val > right->val;
		}
	};

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		// write your code here
		std::priority_queue<ListNode*, std::vector<ListNode*>, Comparator> pq;
		ListNode* dummy = new ListNode(0);
		ListNode* cur_node = dummy;

		for (auto& elem : lists) if (elem) pq.push(elem);

		while (!pq.empty()) {
			cur_node->next = pq.top();
			pq.pop();
			cur_node = cur_node->next;
			if (cur_node->next) pq.push(cur_node->next);
		}

		return dummy->next;
	}
};
