//488. Happy Number

//19 is a happy number
//
//1 ^ 2 + 9 ^ 2 = 82
//8 ^ 2 + 2 ^ 2 = 68
//6 ^ 2 + 8 ^ 2 = 100
//1 ^ 2 + 0 ^ 2 + 0 ^ 2 = 1
//
//1. unordered_map store appeared number, if duplica return false
//2. update next, util next == 1, return true

class Solution {
public:
	/**
	 * @param n: An integer
	 * @return: true if this is a happy number or false
	 */
	bool isHappy(int n) {
		// write your code here
		unordered_set<int> used;
		while (n != 1)
		{
			if (used.count(n)) return false;
			used.insert(n);
			n = findNext(n);
		}
		return true;
	}

	int findNext(int n)
	{
		int res = 0;
		while (n != 0)
		{
			int cur = (n % 10) * (n % 10);
			res += cur;
			n = n / 10;
		}
		return res;
	}
};