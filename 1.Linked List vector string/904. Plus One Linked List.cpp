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
	 * @param head: the first Node
	 * @return: the answer after plus one
	 */
	ListNode* plusOne(ListNode* head) {
		// Write your code here
		ListNode* last = head;
		ListNode* seeker = head;
		while (seeker)
		{
			if (seeker->val != 9)
			{
				last = seeker;
			}
			seeker = seeker->next;
		}
		if (last->val == 9)
		{
			head = new ListNode(1);
			head->next = last;
			last->val = 0;
		}
		else last->val++;
		last = last->next;
		while (last)
		{
			last->val = 0;
			last = last->next;
		}
		return head;
	}
};