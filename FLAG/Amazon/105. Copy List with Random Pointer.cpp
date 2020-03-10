//105. Copy List with Random Pointer
//1. unordered_map deep copy
//1. double length copy after each node
//2. copy random, then split

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
		RandomListNode* cur = head;
		while (cur)
		{
			RandomListNode* new_node = new RandomListNode(cur->label);
			RandomListNode* pilot = cur->next;
			cur->next = new_node;
			new_node->next = pilot;
			cur = pilot;
		}

		RandomListNode* copyList_head = head->next;
		cur = head;
		RandomListNode* copy_cur = copyList_head;
		while (cur)
		{
			if (cur->random) copy_cur->random = cur->random->next;
			if (!cur->next->next) break;
			cur = cur->next->next;
			copy_cur = copy_cur->next->next;
		}

		cur = head;
		copy_cur = copyList_head;
		while (cur)
		{
			RandomListNode* pilot = cur->next->next;
			cur->next = pilot;
			if (!pilot) break;
			RandomListNode* copy_pilot = copy_cur->next->next;
			copy_cur->next = copy_pilot;
			cur = pilot;
			copy_cur = copy_pilot;
		}
		return copyList_head;
	}
};

class Solution {
public:
	/**
	 * @param head: The head of linked list with a random pointer.
	 * @return: A new head of a deep copy of the list.
	 */
	RandomListNode* copyRandomList(RandomListNode* head) {
		// write your code here
		unordered_map<RandomListNode*, RandomListNode*> mp;
		RandomListNode* cur = head;
		while (cur)
		{
			RandomListNode* newNode = new RandomListNode(cur->label);
			mp[cur] = newNode;
			cur = cur->next;
		}
		for (auto item : mp)
		{
			RandomListNode* newNext = item.first->next;
			if (newNext) mp[item.first]->next = mp[newNext];
			else mp[item.first]->next = nullptr;
			RandomListNode* newRandom = item.first->random;
			if (newRandom) mp[item.first]->random = mp[newRandom];
			else mp[item.first]->random = nullptr;
		}
		return mp[head];
	}
};