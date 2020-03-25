//1742. Orderly Queue
//1. if K > 1, eventually we can get the sorted S
//2. if K == 1, for loop the circular string get the smallest one

class Solution {
public:
	/**
	 * @param S: a string
	 * @param K: int
	 * @return: the lexicographically smallest string
	 */
	string orderlyQueue(string& S, int K) {
		// Write your code here.
		if (K > 1)
		{
			sort(S.begin(), S.end());
			return S;
		}
		string res = S;
		for (int i = 1; i < S.size(); i++)
		{
			string next = S.substr(i) + S.substr(0, i);
			if (next < res) res = next;
		}
		return res;
	}
};