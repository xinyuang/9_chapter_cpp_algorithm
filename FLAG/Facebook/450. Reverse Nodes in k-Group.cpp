//450. Reverse Nodes in k - Group
//1. dummy->groupK->last, use count to chunck K, if count < K return dummy->next
//2. reverse groupK


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
			while (cur)
			{
				int count = 0;
				ListNode* first = cur;
				while (cur->next && count < k)
				{
					cur = cur->next;
					count++;
				}
				if (count != k)
				{
					return dummy->next;
				}
				else
				{
					ListNode* last = cur->next;
					cur->next = nullptr;
					ListNode* tail = first->next;
					ListNode* new_list = reverse(first->next);
					first->next = new_list;
					tail->next = last;
					cur = tail;
				}
			}
			return dummy->next;
		}

		ListNode* reverse(ListNode* head)
		{
			ListNode* dummy = new ListNode(0);
			dummy->next = head;
			ListNode* prev = nullptr;
			ListNode* cur = head;
			while (cur)
			{
				ListNode* pilot = cur->next;
				cur->next = prev;
				prev = cur;
				cur = pilot;
			}
			return prev;
		}
};