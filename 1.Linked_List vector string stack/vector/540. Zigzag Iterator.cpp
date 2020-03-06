//540. Zigzag Iterator
//1. pointer pos points to current vector pos = (pos + 1) % 2
//2. iterator begin() == end() switch to next vector

class ZigzagIterator {
private:
	vector<vector<int>::iterator> cur;
	vector<vector<int>::iterator> ends;
	int pos;
public:
	/*
	* @param v1: A 1d vector
	* @param v2: A 1d vector
	*/ZigzagIterator(vector<int>& v1, vector<int>& v2) {
	// do intialization if necessary
	cur.push_back(v1.begin());
	cur.push_back(v2.begin());
	ends.push_back(v1.end());
	ends.push_back(v2.end());
	pos = 0;
}

	  /*
	   * @return: An integer
	   */
	  int next() {
		  // write your code here
		  int res = *cur[pos]++;
		  pos = (pos + 1) % 2;
		  return res;
	  }

	  /*
	   * @return: True if has next
	   */
	  bool hasNext() {
		  // write your code here
		  int count = 0;
		  while (cur[pos] == ends[pos])
		  {
			  pos = (pos + 1) % 2;
			  count++;
			  if (count >= 2) return false;
		  }
		  return true;
	  }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator solution(v1, v2);
 * while (solution.hasNext()) result.push_back(solution.next());
 * Ouptut result
 */