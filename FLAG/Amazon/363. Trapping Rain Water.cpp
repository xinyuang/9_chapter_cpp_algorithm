//363. Trapping Rain Water
//1. water += min(left_max[i], right_max[i]) - height[i]
//1. monotonic decreasing stack, store index
//2.  water += (min(heights[j], heights[i]) - heights[k]) * (i - j - 1);


class Solution {
public:
	/**
	 * @param heights: a list of integers
	 * @return: a integer
	 */
	int trapRainWater(vector<int>& heights) {
		// write your code here
		stack<int> stk;
		int water = 0;
		for (int i = 0; i < heights.size(); i++)
		{
			while (!stk.empty() && heights[stk.top()] < heights[i])
			{
				int k = stk.top(); stk.pop();
				if (!stk.empty())
				{
					int j = stk.top();
					int area = (i - j - 1) * (min(heights[j], heights[i]) - heights[k]);
					water += area;
				}
			}
			stk.push(i);
		}
		return water;
	}
};