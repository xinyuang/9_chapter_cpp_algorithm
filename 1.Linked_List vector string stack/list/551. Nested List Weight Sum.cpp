//551. Nested List Weight Sum
//1. dfs getListSum
//2. depth++, getListSum(ele.getList()), depth--;


class Solution {
public:
	int depthSum(const vector<NestedInteger>& nestedList) {
		// Write your code here
		vector<NestedInteger> cur = nestedList;
		int res = getWeightSum(cur, 1);
		return res;
	}

	int getWeightSum(vector<NestedInteger> nestedList, int depth)
	{
		int sum = 0;
		for (NestedInteger ele : nestedList)
		{
			if (ele.isInteger()) sum += ele.getInteger() * depth;
			else {
				vector<NestedInteger> newList = ele.getList();
				sum += getWeightSum(newList, depth + 1);
			}
		}
		return sum;
	}
};