class RandomizedCollection {
public:
	/** Initialize your data structure here. */
	RandomizedCollection() {

	}

	/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
	bool insert(int val) {
		// write your code here
		bool res = false;
		if (!map.count(val)) res = true;
		map[val].push_back(arrays.size());
		arrays.push_back(val);
		return res;
	}

	/** Removes a value from the collection. Returns true if the collection contained the specified element. */
	bool remove(int val) {
		// write your code here
		if (!map.count(val)) return false;
		int idx = map[val].back();

		int tar_val = arrays.back();
		int last_idx = map[tar_val].back();
		arrays[idx] = arrays[last_idx];
		arrays.pop_back();
		map[tar_val][map[tar_val].size() - 1] = idx;
		map[val].pop_back();
		if (map[val].size() == 0)
		{
			map.erase(val);
		}
		return true;
	}

	/** Get a random element from the collection. */
	int getRandom() {
		// write your code here
		return arrays[rand() % arrays.size()];
	}

private:
	unordered_map<int, vector<int>> map;
	vector<int> arrays;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */