//450. Reverse Nodes in k - Group
//1. dummy, tmp == k reverse, dummy->start, tail->pilot, cur = tail

/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

	class Solution {
	public:
		/**
		 * @param head: a ListNode
		 * @param k: An integer
		 * @return: a ListNode
		 */
		ListNode* reverseKGroup(ListNode* head, int k) {
			// write your code here
			ListNode* dummy = new ListNode(0);
			dummy->next = head;

			ListNode* cur = dummy;
			ListNode* start = dummy;
			int tmp = 0;
			while (cur)
			{
				if (!cur->next) break;
				cur = cur->next;
				tmp++;
				if (tmp == k)
				{
					ListNode* pilot = cur->next;
					cur->next = nullptr;
					ListNode* tail = reverse(start->next);
					start->next = cur;
					if (!pilot) break;
					tail->next = pilot;
					start = tail;
					tmp = 0;
					cur = tail;
				}
			}
			return dummy->next;
		}

		ListNode* reverse(ListNode* head)
		{
			ListNode* prev = nullptr;
			ListNode* cur = head;
			ListNode* tail = head;
			while (cur)
			{

				ListNode* pilot = cur->next;
				cur->next = prev;
				prev = cur;
				if (!pilot) break;
				cur = pilot;
			}
			return tail;
		}
};
