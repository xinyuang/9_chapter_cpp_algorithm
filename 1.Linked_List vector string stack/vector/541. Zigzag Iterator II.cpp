//541. Zigzag Iterator II
//vector<vector<int>::iterator> cur;
//vector<vector<int>::iterator> end;
//1. pointer pos points to current vector pos = (pos + 1) % k
//2. while iterator begin() == end() switch to next vector

class ZigzagIterator2 {
private:
	vector<vector<int>::iterator> cur;
	vector<vector<int>::iterator> end;
	int pos;
	int cap;
public:
	/*
	* @param vecs: a list of 1d vectors
	*/ZigzagIterator2(vector<vector<int>>& vecs) {
	// do intialization if necessary
	for (int i = 0; i < vecs.size(); i++)
	{
		cur.push_back(vecs[i].begin());
		end.push_back(vecs[i].end());
	}
	pos = 0;
	cap = vecs.size();
}

	  /*
	   * @return: An integer
	   */
	  int next() {
		  // write your code here
		  int res = *cur[pos]++;
		  pos = (pos + 1) % cap;
		  return res;
	  }

	  /*
	   * @return: True if has next
	   */
	  bool hasNext() {
		  // write your code here
		  int count = 0;
		  while (cur[pos] == end[pos]) {
			  pos = (pos + 1) % cap;
			  count++;
			  if (count > cap) return false;
		  }
		  return true;
	  }
};

/**
 * Your ZigzagIterator2 object will be instantiated and called as such:
 * ZigzagIterator2 solution(vecs);
 * while (solution.hasNext()) result.push_back(solution.next());
 * Ouptut result
 */