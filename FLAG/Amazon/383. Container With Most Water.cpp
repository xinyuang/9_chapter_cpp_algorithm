//383. Container With Most Water
//left, right, move the smaller one, update max_area

class Solution {
public:
	/**
	 * @param heights: a vector of integers
	 * @return: an integer
	 */
	int maxArea(vector<int>& heights) {
		// write your code here
		int left = 0, right = heights.size() - 1;
		int max_area = 0;
		while (left < right)
		{
			int curArea = min(heights[right], heights[left]) * (right - left);
			max_area = max(curArea, max_area);
			if (heights[left] < heights[right]) left++;
			else right--;
		}
		return max_area;
	}
};