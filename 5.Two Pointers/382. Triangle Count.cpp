//1. for loop the largest edge left = 0, right = i - 1, when right--, left won't change direction
//2. while (left < right) if valid(count += (right - left)
//	O(n2)
//             [2,4,5,6,8,9,10,13,14]
//              x v v v v v v  T  
//              x x v v v v  
class Solution {
public:
	/**
	 * @param S: A list of integers
	 * @return: An integer
	 */
	int triangleCount(vector<int>& S) {
		// write your code here
		sort(S.begin(), S.end());
		int left = 0;
		int count = 0;
		for (int i = S.size() - 1; i >= 2; i--)
		{
			int left = 0, right = i - 1;
			while (left < right)
			{
				if (S[left] + S[right] <= S[i]) left++;
				else {
					count += (right - left);
					right--;
				}
			}
		}
		return count;
	}
};