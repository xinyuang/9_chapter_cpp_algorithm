165. Merge Two Sorted Lists


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
		 * @param l1: ListNode l1 is the head of the linked list
		 * @param l2: ListNode l2 is the head of the linked list
		 * @return: ListNode head of linked list
		 */
		ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
			// write your code here
			ListNode* cur_l1 = l1;
			ListNode* cur_l2 = l2;
			ListNode* dummy = new ListNode(0);
			ListNode* cur = dummy;
			while (cur_l1 && cur_l2)
			{
				if (cur_l1->val < cur_l2->val)
				{
					cur->next = cur_l1;
					cur_l1 = cur_l1->next;
				}
				else
				{
					cur->next = cur_l2;
					cur_l2 = cur_l2->next;
				}
				cur = cur->next;
			}
			while (cur_l1)
			{
				cur->next = cur_l1;
				cur_l1 = cur_l1->next;
				cur = cur->next;
			}
			while (cur_l2)
			{
				cur->next = cur_l2;
				cur_l2 = cur_l2->next;
				cur = cur->next;
			}
			return dummy->next;
		}
};