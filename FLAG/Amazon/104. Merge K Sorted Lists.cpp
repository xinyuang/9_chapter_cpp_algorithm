//104. Merge K Sorted Lists
//merge sort(start, end in array)
//min_heap<ListNode*, vector<ListNode*>, com>

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
		class com {
		public:
			bool operator() (const ListNode* a, const ListNode* b)
			{
				return a->val > b->val;
			}
		};
		priority_queue<ListNode*, vector<ListNode*>, com> min_heap;
		for (int i = 0; i < lists.size(); i++)
		{
			if (!lists[i]) continue;
			min_heap.push(lists[i]);
		}
		ListNode* dummy = new ListNode(0);
		ListNode* cur = dummy;
		while (!min_heap.empty())
		{
			ListNode* node = min_heap.top(); min_heap.pop();
			cur->next = node;
			cur = cur->next;
			if (node->next) min_heap.push(node->next);
		}
		return dummy->next;
	}
};

class Solution {
public:
	/**
	 * @param lists: a list of ListNode
	 * @return: The head of one sorted list.
	 */
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		// write your code here
		int left = 0, right = lists.size() - 1;
		ListNode* res = mergeK(left, right, lists);
		return res;
	}

	ListNode* mergeK(int start, int end, vector<ListNode*>& lists)
	{
		if (start >= end) return lists[start];
		int mid = (end - start) / 2 + start;
		ListNode* first = mergeK(start, mid, lists);
		ListNode* second = mergeK(mid + 1, end, lists);
		ListNode* res = mergeSort(first, second);
		return res;
	}

	ListNode* mergeSort(ListNode* a, ListNode* b)
	{
		ListNode* dummy = new ListNode(0);
		ListNode* cur = dummy;
		while (a && b)
		{
			if (a->val < b->val)
			{
				cur->next = a;
				a = a->next;
				cur = cur->next;
			}
			else
			{
				cur->next = b;
				b = b->next;
				cur = cur->next;
			}
		}

		while (a)
		{
			cur->next = a;
			a = a->next;
			cur = cur->next;
		}

		while (b)
		{
			cur->next = b;
			b = b->next;
			cur = cur->next;
		}
		return dummy->next;
	}
};
