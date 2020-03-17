//451. Swap Nodes in Pairs

//D -> n1 -> n2 -> n3 -> n4 ->nullptr
//
//D ->( n2 -> n1 )-> n3 -> n4 ->nullptr
//
//start from D, swap next two nodes
//start from n1, swap next two nodes


//class ListNode {
// public:
//  int value;
//  ListNode* next;
//  ListNode(int v) : value(v), next(NULL) {}
//};
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
		head = dummy;
		while (head->next && head->next->next)
		{
			ListNode* pilot = head->next->next->next;
			ListNode* n1 = head->next->next;
			ListNode* n2 = head->next;
			head->next = n1;
			n1->next = n2;
			n2->next = pilot;
			head = n2;
		}
		return dummy->next;
	}
};
