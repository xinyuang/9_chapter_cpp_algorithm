// 372. Delete Node in a Linked List
// given the node tobe deleted, just assign next node to this node and delete the next one

class Solution {
public:
    /*
     * @param node: the node in the list should be deleted
     * @return: nothing
     */
    void deleteNode(ListNode * node) {
        // write your code here
        if(!node) return;
        if(!node->next)
        {
            node = nullptr;
            return;
        }
        node->val = node->next->val;
        node->next = node->next->next;
    }
};