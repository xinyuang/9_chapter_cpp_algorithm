//400. Maximum Gap
//1. bucket sort, base = (max - min) / (n - 1)
//2. bucket store min, max, isEmpty
//3. loop bucket gap = max(gap, bucket.min - last bucket.max)

class Bucket {
public:
	int min;
	int max;
	bool isEmpty;
	Bucket() : min(INT_MAX), max(INT_MIN), isEmpty(true) {}
};

class Solution {
public:
	/**
	 * @param nums: an array of integers
	 * @return: the maximun difference
	 */
	int maximumGap(vector<int>& nums) {
		// write your code here
		int min_v = INT_MAX, max_v = INT_MIN;
		for (int i = 0; i < nums.size(); i++)
		{
			min_v = min(min_v, nums[i]);
			max_v = max(max_v, nums[i]);
		}
		if (nums.size() < 2 || min_v == max_v) return 0;
		int n = nums.size();
		int base = ceil(double(max_v - min_v) / (n - 1));
		vector<Bucket> bkt(n);
		for (int i = 0; i < nums.size(); i++)
		{
			int pos = floor((nums[i] - min_v) / base);
			bkt[pos].min = min(bkt[pos].min, nums[i]);
			bkt[pos].max = max(bkt[pos].max, nums[i]);
			bkt[pos].isEmpty = false;
		}
		int gap = 0;
		int lastMax = min_v;
		for (int i = 0; i < bkt.size(); i++)
		{
			if (bkt[i].isEmpty) continue;
			int cur_gap = bkt[i].min - lastMax;
			gap = max(gap, cur_gap);
			lastMax = bkt[i].max;
		}
		return gap;
	}
};