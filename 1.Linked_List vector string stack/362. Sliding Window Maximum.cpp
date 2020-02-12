// Sliding Window Maximum
// monotinic decreasing deque
// [4,2,1,6,7,8]  k = 2  dq  do a for loop
//  if nums[cur - k] == dq.front() => dq.pop_front()
//  if nums[cur] > dq.back() => dq.pop_back()
//  dq.push_back(cur)
class Solution {
public:
	/**
	 * @param nums: A list of integers.
	 * @param k: An integer
	 * @return: The maximum number inside the window at each moving.
	 */
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		// write your code here
		vector<int> res;
		deque<int> dq;
		for (int i = 0; i < nums.size(); i++)
		{
			if (!dq.empty() && dq.front() == i - k) dq.pop_front();
			while (!dq.empty() && nums[dq.back()] <= nums[i])
			{
				dq.pop_back();
			}
			dq.push_back(i);
			if (i - k + 1 >= 0) res.push_back(nums[dq.front()]);
		}
		return res;
	}
};