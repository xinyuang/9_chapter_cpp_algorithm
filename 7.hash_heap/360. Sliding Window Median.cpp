//360. Sliding Window Median
//1. multiset<int> min, max, init with k
//2. erase set.find(nums[i - k]), insert nums[i]
//3. rbegin() is reverse iterator, cannot be used in erase function directly
//4. valid_check() adjust min,max_set to ensure *max_set.rbegin() is the median

class Solution {
public:
	/**
	 * @param nums: A list of integers
	 * @param k: An integer
	 * @return: The median of the element inside the window at each moving
	 */
	vector<int> medianSlidingWindow(vector<int>& nums, int k) {
		// write your code here
		if (nums.size() == 0 || k == 0) return {};
		multiset<int> min_set, max_set;
		for (int i = 0; i < k; i++)
		{
			max_set.insert(nums[i]);
		}
		for (int i = 0; i < k / 2; i++)
		{
			int cur = *max_set.rbegin();
			max_set.erase(max_set.find(*max_set.rbegin()));
			min_set.insert(cur);
		}
		vector<int> res;
		res.push_back(*max_set.rbegin());
		for (int i = k; i < nums.size(); i++)
		{
			if (min_set.count(nums[i - k]))
			{
				min_set.erase(min_set.find(nums[i - k]));
				min_set.insert(nums[i]);
			}
			else {
				max_set.erase(max_set.find(nums[i - k]));
				max_set.insert(nums[i]);
			}
			valid_check(min_set, max_set);
			res.push_back(*max_set.rbegin());
		}
		return res;
	}

	void valid_check(multiset<int>& min_set, multiset<int>& max_set)
	{
		if (min_set.empty() || max_set.empty()) return;
		int last = *max_set.rbegin();
		int first = *min_set.begin();
		if (last > first)
		{
			max_set.erase(max_set.find(last));
			min_set.erase(min_set.find(first));
			min_set.insert(last);
			max_set.insert(first);
		}
	}
};