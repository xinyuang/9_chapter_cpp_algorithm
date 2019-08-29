map<string, int> mp;
class compare {
public:
	bool operator()(const string& a, const string& b)
	{
		int count_a = mp[a];
		int count_b = mp[b];
		if (count_a == count_b)
		{
			return a < b;   // small string first
		}
		return count_b < count_a;
	}
};
class TopK {
public:
	/*
	* @param k: An integer
	*/TopK(int k) {
	// do intialization if necessary
	stream_size = k;
}

	  /*
	   * @param word: A string
	   * @return: nothing
	   */
	  void add(string& word) {
		  // write your code here
		  if (RBtree.find(word) != RBtree.end()) RBtree.erase(RBtree.find(word));
		  mp[word]++;
		  RBtree.insert(word);
		  if (RBtree.size() > stream_size)
		  {
			  RBtree.erase(--RBtree.end());
		  }
	  }

	  /*
	   * @return: the current top k frequent words.
	   */
	  vector<string> topk() {
		  // write your code here
		  vector<string> res(RBtree.begin(), RBtree.end());
		  return res;
	  }
private:
	int stream_size;
	set<string, compare> RBtree;  // descedent order 
};