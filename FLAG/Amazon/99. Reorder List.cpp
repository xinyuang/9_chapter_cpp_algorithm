//99. Reorder List
//1. split list into two equal parts
//2. reverse the last part
//3. merge two lists

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
     * @return: nothing
     */
    void reorderList(ListNode * head) {
        // write your code here
        if(!head) return;
        ListNode* L2 = splitList(head);
        ListNode* rev_l2 = reverse(L2);
        merge(head,rev_l2);
    }
    
    ListNode* splitList(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* L2 = slow->next;
        slow->next = nullptr;
        return L2;
    }
    
    ListNode* reverse(ListNode* a)
    {
        ListNode* head = a;
        ListNode* cur = a;
        ListNode* prev = nullptr;
        while(cur)
        {
            ListNode* pilot = cur->next;
            cur->next = prev;
            prev = cur;
            cur = pilot;
        }
        return prev;
    }
    
    void merge(ListNode* a, ListNode* b)
    {
        ListNode* cur = a;
        while(a && b)
        {
            a = a->next;
            cur->next = b;
            cur = cur->next;
            b = b->next;
            cur->next = a;
            cur = cur->next;
        }
    }
};