// Trapping Rain Water
// left to right scan, right to left scan
// res += min(left,right) - A[i]
class Solution {
public:
	/**
	 * @param heights: a list of integers
	 * @return: a integer
	 */
	int trapRainWater(vector<int>& heights) {
		// write your code here
		if (heights.size() == 0) return 0;
		int n = heights.size();
		vector<int> left(n, 0);
		vector<int> right(n, 0);
		left[0] = heights[0];
		for (int i = 1; i < n; i++)
		{
			left[i] = max(heights[i], left[i - 1]);
		}
		right[n - 1] = heights[n - 1];
		for (int i = n - 2; i >= 0; i--)
		{
			right[i] = max(heights[i], right[i + 1]);
		}
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			res += min(left[i], right[i]) - heights[i];
		}
		return res;
	}
};



// Monotonic decreasing stack (min(A[i],A[K]) - A[j]) *(i - k - 1)
// 2,1,3,1,5
// . . i
// k j i
class Solution {
public:
	/**
	 * @param heights: a list of integers
	 * @return: a integer
	 */
	int trapRainWater(vector<int>& heights) {
		// write your code here
		stack<int> stk;
		int res = 0;
		for (int i = 0; i < heights.size(); i++)
		{
			while (!stk.empty() && heights[stk.top()] < heights[i])
			{
				int j = stk.top(); stk.pop();
				if (!stk.empty())
				{
					int k = stk.top();
					int dist = i - k - 1;
					res += dist * (min(heights[k], heights[i]) - heights[j]);
				}
			}
			stk.push(i);
		}
		return res;
	}
};