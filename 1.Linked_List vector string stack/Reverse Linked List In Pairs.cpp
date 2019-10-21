// Reverse Linked List In Pairs
//class ListNode {
// public:
//  int value;
//  ListNode* next;
//  ListNode(int v) : value(v), next(NULL) {}
//};
class Solution {
public:
	ListNode* reverseInPairs(ListNode* head) {
		// write your solution here
		int count = -1;
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* old = dummy;
		ListNode* cur = dummy;
		ListNode* pilot = cur;
		ListNode* anchor = dummy;
		//    *->1->2->3->4->nullptr
   //         a  o  c  p
   //         a  c  o  p
   //            a  o  c  p
		while (cur)
		{
			pilot = cur->next;
			count++;
			if (count % 2 == 0)
			{
				//   cout << anchor->val << " " << old->val << " " << cur->val << " " << pilot->val << endl;
				anchor->next = cur;
				cur->next = old;
				old->next = pilot;
				anchor = cur;
				cur = pilot;

			}
			else {
				anchor = old;
				old = cur;
				cur = cur->next;
			}

		}
		return dummy->next;
	}
};
