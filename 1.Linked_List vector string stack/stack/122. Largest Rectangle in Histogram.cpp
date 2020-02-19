// Largest Rectangle in Histogram
// Monotonic increase stack (i - k - 1)*height[j]
//   1,3,2,5,1
//   . .   . 
//   k     j i
class Solution {
public:
	/**
	 * @param height: A list of integer
	 * @return: The area of largest rectangle in the histogram
	 */
	int largestRectangleArea(vector<int>& height) {
		// write your code here
		stack<int> stk;
		int g_area = 0;
		for (int i = 0; i <= height.size(); i++)
		{
			while (!stk.empty() && height[stk.top()] > (i == height.size() ? 0 : height[i]))
			{
				int j = stk.top(); stk.pop();
				int k = -1;
				if (!stk.empty()) k = stk.top();
				int area = (i - k - 1) * height[j];
				if (area > g_area) g_area = area;
			}
			stk.push(i);
		}
		return g_area;
	}
};
