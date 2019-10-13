// Reverse Linked List II
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
	 * @param head: ListNode head is the head of the linked list
	 * @param m: An integer
	 * @param n: An integer
	 * @return: The head of the reversed ListNode
	 */

	 // @->1 -> 2 -> 3 -> 4 -> 5 -> 6 -> nullptr
	 // l  t         h    r
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		// write your code here
		ListNode* dummy = new ListNode(0);
		ListNode* left = dummy;
		ListNode* tail = nullptr;
		ListNode* right = nullptr;
		dummy->next = head;
		ListNode* cur = head;
		int idx = 0;
		while (cur)
		{
			idx++;
			if (idx == m - 1) left = cur;
			if (idx == m) tail = cur;
			if (idx == n) head = cur;
			if (idx == n + 1) right = cur;
			cur = cur->next;
		}
		head->next = nullptr;
		ListNode* target = tail;
		ListNode* reversed = reverse(target);
		left->next = reversed;
		tail->next = right;
		return dummy->next;
	}

	//  nullptr <-1 <- 2 <- 3 -> nullptr
	//                      l     c    p
	ListNode* reverse(ListNode* target)
	{
		if (!target || !target->next) return target;
		ListNode* prev = nullptr;
		ListNode* cur = target;
		ListNode* pilot = target->next;
		while (cur)
		{
			pilot = cur->next;
			cur->next = prev;
			prev = cur;
			cur = pilot;
		}
		return prev;
	}
};