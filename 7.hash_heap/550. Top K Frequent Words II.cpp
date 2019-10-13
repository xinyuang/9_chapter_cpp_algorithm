// Top K frequent words II  online
// RedblackTree map<string,freq>
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

// Map Reduce

/**
 * Definition of Input:
 * template<class T>
 * class Input {
 * public:
 *     bool done();
 *         // Returns true if the iteration has elements or false.
 *     void next();
 *         // Move to the next element in the iteration
 *         // Runtime error if the iteration has no more elements
 *     T value();
 *        // Get the current element, Runtime error if
 *        // the iteration has no more elements
 * }
 * Definition of Document:
 * class Document {
 * public:
 *     int id; // document id
 *     string content; // document content
 * }
 */
class Mypair {
public:
	string key;
	int value;
	Mypair(string k, int v) :key(k), value(v) {}

	bool operator< (const Mypair& b) const
	{
		if (b.value == value)
		{
			return key < b.key;
		}
		return b.value < value;
	}
};
class TopKFrequentWordsMapper : public Mapper {
public:
	void Map(Input<Document>* input) {
		// Write your code here
		// Please directly use func 'output' to output 
		// the results into output buffer.
		// void output(string &key, int value);
		while (!input->done())
		{
			vector<string> words = split(input->value().content, " ");
			for (string word : words)
			{
				if (word.size() > 0) output(word, 1);
			}
			input->next();
		}
	}
	vector<string> split(const string& s, string delimiter)
	{
		int last_idx = 0; int idx = 0;
		vector<string> words;
		while ((idx = s.find(delimiter, last_idx)) != string::npos)
		{

			string seg = s.substr(last_idx, idx - last_idx);
			words.push_back(seg);
			last_idx = idx + delimiter.size();
		}
		if (last_idx != s.size())
		{
			words.push_back(s.substr(last_idx));
		}
		return words;
	}
};


class TopKFrequentWordsReducer : public Reducer {
private:
	int k;
	priority_queue<Mypair> q; //min_heap
public:
	void setUp(int k) {
		// initialize your data structure here
		this->k = k;
	}

	void Reduce(string& key, Input<int>* input) {
		// Write your code here     
		int sum = 0;
		while (!input->done())
		{
			sum += input->value();
			input->next();
		}
		Mypair m(key, sum);
		if (q.size() < k)
		{
			q.push(m);
		}
		else {
			q.push(m);
			q.pop();
		}

	}

	void cleanUp() {
		// Please directly use func 'output' to output 
		// the top k pairs <word, times> into output buffer.
		// void output(string &key, int &value);
		vector<Mypair> array;
		while (!q.empty())
		{
			array.push_back(q.top());
			q.pop();
		}
		for (int i = array.size() - 1; i >= 0; i--)
		{
			output(array[i].key, array[i].value);
		}
	}
};