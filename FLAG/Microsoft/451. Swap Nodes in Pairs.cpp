//451. Swap Nodes in Pairs

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
		 * @return: a ListNode
		 */
		ListNode* swapPairs(ListNode* head) {
			// write your code here
			ListNode* dummy = new ListNode(0);
			dummy->next = head;
			ListNode* cur = dummy;
			while (cur->next && cur->next->next)
			{
				ListNode* n1 = cur->next;
				ListNode* n2 = cur->next->next;
				ListNode* pilot = cur->next->next->next;
				cur->next = n2;
				n2->next = n1;
				n1->next = pilot;
				cur = n1;
			}
			return dummy->next;
		}
};