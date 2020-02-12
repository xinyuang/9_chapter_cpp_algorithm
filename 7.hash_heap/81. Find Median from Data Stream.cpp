// Find Median from Data Stream
// max_heap.size()  > min_heap.size()  push min_heap
//  [      ]  [    ]  return max_heap.top()   or (max_heap.top() + min_heap.top())/2.0
class Solution {
public:
	/**
	 * @param nums: A list of integers
	 * @return: the median of numbers
	 */
	struct compare {
		bool operator()(int a, int b)
		{
			return b < a;
		}
	};
	vector<int> medianII(vector<int>& nums) {
		// write your code here
		map<int, int> stream;
		vector<int> res;
		for (int i = 0; i < nums.size(); i++)
		{
			addNum(nums[i]);
			res.push_back(max_heap.top());
		}
		return res;
	}

	void addNum(int num)
	{
		if (max_heap.size() <= min_heap.size()) max_heap.push(num);
		else min_heap.push(num);
		if (min_heap.size() == 0 || max_heap.size() == 0) return;
		if (max_heap.top() > min_heap.top())
		{
			int large = max_heap.top();
			int small = min_heap.top();
			max_heap.pop();
			min_heap.pop();
			max_heap.push(small);
			min_heap.push(large);
		}
	}

private:
	priority_queue<int> max_heap;
	priority_queue<int, vector<int>, compare> min_heap;
};