//1389. Create Target Array in the Given Order
//1. Linked List insert to the index position
//2.  convert list to vector return res

class myListNode {
public:
	int val;
	myListNode* next;
	myListNode(int v)
	{
		val = v;
		next = nullptr;
	}
};
class Solution {
public:
	vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
		myListNode* dummy = new myListNode(0);
		myListNode* cur = dummy;
		for (int i = 0; i < nums.size(); i++)
		{
			myListNode* newNode = new myListNode(nums[i]);
			int idx = index[i];
			cur = dummy;

			for (int i = 0; i < idx; i++)
			{
				cur = cur->next;
			}
			myListNode* pilot = cur->next;
			cur->next = newNode;
			newNode->next = pilot;
			cur = dummy->next;
		}
		cur = dummy->next;
		vector<int> tar;
		while (cur)
		{
			tar.push_back(cur->val);
			cur = cur->next;
		}
		return tar;
	}
};