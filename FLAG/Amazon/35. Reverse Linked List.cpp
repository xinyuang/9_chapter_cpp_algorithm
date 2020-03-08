//35. Reverse Linked List
//1. pilot, cur, prev
//2. while (pilot) reverse, return cur

/**
 * Definition of singly-linked-list:
 *
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
		 * @param head: n
		 * @return: The new head of reversed linked list.
		 */
		ListNode* reverse(ListNode* head) {
			// write your code here
			ListNode* cur = nullptr;
			ListNode* pilot = head;
			while (pilot)
			{
				ListNode* new_pilot = pilot->next;
				pilot->next = cur;
				cur = pilot;
				pilot = new_pilot;
			}
			return cur;
		}
};