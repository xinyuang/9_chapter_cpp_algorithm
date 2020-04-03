//380. Intersection of Two Linked Lists
//1. tailA->next = headB, find circle start point with slow and fast
//2. after fast = slow, reset fast = head, slow = slow->next, find inter node

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
		 * @param headA: the first list
		 * @param headB: the second list
		 * @return: a ListNode
		 */
		ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
			// write your code here
			if (!headA || !headB) return nullptr;
			ListNode* cur = headA;

			while (cur->next)
			{
				cur = cur->next;
			}
			cur->next = headB;
			ListNode* res = findInter(headA);
			return res;
		}

		ListNode* findInter(ListNode* head)
		{
			ListNode* slow = head;
			ListNode* fast = head->next;
			while (fast != slow && fast && fast->next)
			{
				fast = fast->next->next;
				slow = slow->next;
			}
			fast = head;
			slow = slow->next;
			while (fast != slow)
			{
				fast = fast->next;
				slow = slow->next;
			}
			return slow;
		}
};