class Solution {
public:
	/*
	* @param k: An integer
	*/Solution(int k) {
	// do intialization if necessary
	cache_size = k;
}

	  /*
	   * @param num: Number to be added
	   * @return: nothing
	   */
	  void add(int num) {
		  // write your code here
		  min_heap.push(num);
		  if (min_heap.size() > cache_size) min_heap.pop();
	  }

	  /*
	   * @return: Top k element
	   */
	  vector<int> topk() {
		  // write your code here
		  vector<int> res;
		  while (!min_heap.empty())
		  {
			  res.push_back(min_heap.top());
			  min_heap.pop();
		  }
		  reverse(res.begin(), res.end());
		  for (int ele : res)
		  {
			  min_heap.push(ele);
		  }
		  return res;
	  }
private:
	int cache_size = 0;
	struct compare {
		bool operator() (int a, int b)
		{
			return b < a;
		}
	};
	priority_queue<int, vector<int>, compare> min_heap;

};