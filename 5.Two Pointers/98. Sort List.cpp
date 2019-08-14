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
	 * @param head: The head of linked list.
	 * @return: You should return the head of the sorted linked list, using constant space complexity.
	 */
	ListNode* sortList(ListNode* head) {
		// write your code here
		ListNode* res = mergeSort(head);
		return res;
	}

	ListNode* mergeSort(ListNode* head)
	{
		if (!head) return nullptr;
		if (!head->next) return head;
		ListNode* slow = head;
		ListNode* fast = head->next;
		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}

		ListNode* right = slow->next;
		slow->next = nullptr;
		ListNode* left = head;

		ListNode* list1 = mergeSort(right);
		ListNode* list2 = mergeSort(left);

		return merge(list1, list2);
	}

	ListNode* merge(ListNode* a, ListNode* b)
	{
		ListNode* dummy = new ListNode(0);
		ListNode* cur = dummy;
		while (a && b)
		{
			if (a->val < b->val)
			{
				cur->next = a;
				cur = cur->next;
				a = a->next;
			}
			else
			{
				cur->next = b;
				cur = cur->next;
				b = b->next;
			}
		}
		while (a)
		{
			cur->next = a;
			cur = cur->next;
			a = a->next;
		}
		while (b)
		{
			cur->next = b;
			cur = cur->next;
			b = b->next;
		}
		return dummy->next;
	}
};