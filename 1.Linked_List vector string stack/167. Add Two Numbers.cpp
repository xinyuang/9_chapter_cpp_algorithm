// Add Two Numbers
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
	 * @param l1: the first list
	 * @param l2: the second list
	 * @return: the sum list of l1 and l2
	 */
	ListNode* addLists(ListNode* l1, ListNode* l2) {
		// write your code here
		int carry = 0;
		ListNode* dummy = new ListNode(0);
		ListNode* cur = dummy;
		while (true)
		{
			if (l1)
			{
				carry += l1->val;
				l1 = l1->next;
			}
			if (l2)
			{
				carry += l2->val;
				l2 = l2->next;
			}
			cur->next = new ListNode(carry % 10);
			carry = carry / 10;
			cur = cur->next;
			if (!l1 && !l2 && carry == 0) break;
		}
		return dummy->next;
	}
};

// If the reverted lists are given
class Solution {
public:
	/**
	 * @param l1: The first list.
	 * @param l2: The second list.
	 * @return: the sum list of l1 and l2.
	 */
	ListNode* addLists2(ListNode* l1, ListNode* l2) {
		// write your code here
		ListNode* rl1 = reverse(l1);
		ListNode* rl2 = reverse(l2);
		ListNode* dummy = new ListNode(0);
		ListNode* cur = dummy;
		int carry = 0;
		while (true)
		{
			if (rl1)
			{
				carry += rl1->val;
				rl1 = rl1->next;
			}
			if (rl2)
			{
				carry += rl2->val;
				rl2 = rl2->next;
			}
			cur->next = new ListNode(carry % 10);
			carry = carry / 10;
			cur = cur->next;
			if (!rl1 && !rl2 && carry == 0) break;
		}
		ListNode* res = reverse(dummy->next);
		return res;
	}
	// nullptr  <-  1 <- 2 <- 3 -> NULL
	//         p    c    n
	ListNode* reverse(ListNode* head)
	{
		ListNode* dummy = head;
		ListNode* prev = nullptr;
		ListNode* cur = head;
		ListNode* next = cur;
		while (cur)
		{
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		return prev;
	}
};