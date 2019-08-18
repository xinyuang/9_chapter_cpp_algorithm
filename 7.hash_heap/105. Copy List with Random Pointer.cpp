/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
	/**
	 * @param head: The head of linked list with a random pointer.
	 * @return: A new head of a deep copy of the list.
	 */
	RandomListNode* copyRandomList(RandomListNode* head) {
		// write your code here
		unordered_map<RandomListNode*, RandomListNode*> map;
		RandomListNode* dummy = head;
		while (head)
		{
			RandomListNode* newNode = new RandomListNode(head->label);
			map[head] = newNode;
			head = head->next;

		}
		for (auto item : map)
		{
			if (item.first->next) item.second->next = map[item.first->next];
			else item.second->next = nullptr;
			if (item.first->random) item.second->random = map[item.first->random];
			else item.second->random = nullptr;
		}
		return map[dummy];
	}
};