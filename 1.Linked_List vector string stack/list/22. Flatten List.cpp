//22. Flatten List
//1. recursive method
//2. non recursive way

class Solution {
public:
	// @param nestedList a list of NestedInteger
	// @return a list of integer
	vector<int> flatten(vector<NestedInteger>& nestedList) {
		// Write your code here
		vector<int> res;
		for (NestedInteger ele : nestedList)
		{
			if (ele.isInteger()) res.push_back(ele.getInteger());
			else {
				vector<NestedInteger> new_list = ele.getList();
				vector<int> sub = flatten(new_list);
				for (int i = 0; i < sub.size(); i++) res.push_back(sub[i]);
			}
		}
		return res;
	}
};

class Solution {
public:
	// @param nestedList a list of NestedInteger
	// @return a list of integer
	vector<int> flatten(vector<NestedInteger>& nestedList) {
		// Write your code here
		bool hashNested = true;
		while (hashNested)
		{
			hashNested = false;
			vector<NestedInteger> newList;
			for (auto ele : nestedList)
			{
				if (ele.isInteger()) newList.push_back(ele);
				else {
					vector<NestedInteger> flat = ele.getList();
					for (auto i : flat) newList.push_back(i);
					hashNested = true;
				}
			}
			nestedList = newList;
		}
		vector<int> res;
		for (auto i : nestedList) res.push_back(i.getInteger());
		return res;
	}
};