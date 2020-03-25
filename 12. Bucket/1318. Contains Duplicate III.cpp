1318. Contains Duplicate III

1. use unordered_map, bucket sort, bucket size is t + 1, check neighbor buckets id + 1, id, d - 1
each bucket has only one value, if it has multiple value, it absolutely meet the requirement

class Solution {
public:
	/**
	 * @param nums: the given array
	 * @param k: the given k
	 * @param t: the given t
	 * @return: whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.
	 */
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		// Write your code here
		unordered_map<int, int> bucket;
		int width = t + 1;
		for (int i = 0; i < nums.size(); i++)
		{
			int id = getBucketID(nums[i], width);
			if (bucket.count(id)) return true;
			if (bucket.count(id - 1) && abs(nums[i] - bucket[id - 1]) <= t) return true;
			if (bucket.count(id + 1) && abs(nums[i] - bucket[id + 1]) <= t) return true;
			if (i >= k)
			{
				int old_id = getBucketID(nums[i - k], width);
				if (bucket.count(old_id)) bucket.erase(old_id);
			}
			bucket[id] = nums[i];
		}
		return false;
	}

	int getBucketID(int value, int w)
	{
		return value / w;
	}
};

// use multisort to store window K numbser, find two closest number using lower_bound, check abs(*it - number[i]) 
class Solution {
public:
	/**
	 * @param nums: the given array
	 * @param k: the given k
	 * @param t: the given t
	 * @return: whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.
	 */
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		// Write your code here
		multiset<int> st;
		for (int i = 0; i < nums.size(); i++)
		{
			if (i > k) st.erase(st.find(nums[i - k - 1]));
			auto it = st.lower_bound(nums[i]);
			if (it != st.end() && abs(*it - nums[i]) <= t) return true;
			if (it != st.begin() && abs(*--it - nums[i]) <= t) return true;
			st.insert(nums[i]);
		}
		return false;
	}
};