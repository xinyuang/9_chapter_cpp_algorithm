//362. Sliding Window Maximum
//1. use multiset to store window number
//1. deque(monotonic decreasing) store idx  when dq.front() == i - k, pop_front()

class Solution {
public:
	/**
	 * @param nums: A list of integers.
	 * @param k: An integer
	 * @return: The maximum number inside the window at each moving.
	 */
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		// write your code here
		multiset<int> st;
		vector<int> res;
		if (k > nums.size() || nums.size() == 0) return {};
		for (int i = 0; i < k; i++)
		{
			st.insert(nums[i]);
		}
		res.push_back(*st.rbegin());
		for (int i = k; i < nums.size(); i++)
		{
			st.erase(st.find(nums[i - k]));
			st.insert(nums[i]);
			res.push_back(*st.rbegin());
		}
		return res;
	}
};

class Solution {
public:
	/**
	 * @param nums: A list of integers.
	 * @param k: An integer
	 * @return: The maximum number inside the window at each moving.
	 */
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		// write your code here
		if (nums.size() == 0 || k > nums.size()) return {};
		deque<int> dq;
		vector<int> res;
		for (int i = 0; i < nums.size(); i++)
		{
			int cur = nums[i];
			while (!dq.empty() && cur > nums[dq.back()]) dq.pop_back();
			dq.push_back(i);
			if (!dq.empty() && dq.front() == i - k) dq.pop_front();
			if (i >= k - 1) res.push_back(nums[dq.front()]);
		}
		return res;
	}
};