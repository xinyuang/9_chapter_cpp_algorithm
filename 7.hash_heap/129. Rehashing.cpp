//  Rehash

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
	/**
	 * @param hashTable: A list of The first node of linked list
	 * @return: A list of The first node of linked list which have twice size
	 */
	vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
		// write your code here
		vector<ListNode*> rehash(hashTable.size() * 2, nullptr);
		for (int i = 0; i < hashTable.size(); i++)
		{
			ListNode* cur = hashTable[i];
			while (cur)
			{
				ListNode* newNode = new ListNode(cur->val);
				addNode(rehash, newNode);
				cur = cur->next;
			}
		}
		return rehash;
	}

	void addNode(vector<ListNode*>& rehash, ListNode* newNode)
	{
		int hashcode = (newNode->val + rehash.size()) % rehash.size();
		if (!rehash[hashcode])
		{
			rehash[hashcode] = newNode;
		}
		else
		{
			ListNode* head = rehash[hashcode];
			ListNode* prev = head;
			while (head)
			{
				prev = head;
				head = head->next;
			}
			prev->next = newNode;
		}
	}
};