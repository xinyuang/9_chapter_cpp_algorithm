//528. Flatten Nested List Iterator
//1. stack reverse store vector
//2. while (!stk.empty()) flat vector till the top is integer

class NestedIterator {
private:
	stack<NestedInteger> stk;
public:
	NestedIterator(vector<NestedInteger>& nestedList) {
		// Initialize your data structure here.

		for (int i = nestedList.size() - 1; i >= 0; i--)
		{
			stk.push(nestedList[i]);
		}
	}

	// @return {int} the next element in the iteration
	int next() {
		// Write your code here
		NestedInteger cur = stk.top(); stk.pop();
		return cur.getInteger();
	}

	// @return {boolean} true if the iteration has more element or false
	bool hasNext() {
		// Write your code here
		if (stk.empty()) return false;
		while (!stk.empty() && !stk.top().isInteger())
		{
			vector<NestedInteger> subList = stk.top().getList();
			stk.pop();
			for (int i = subList.size() - 1; i >= 0; i--)
			{
				stk.push(subList[i]);
			}
		}
		return !stk.empty();
	}
};