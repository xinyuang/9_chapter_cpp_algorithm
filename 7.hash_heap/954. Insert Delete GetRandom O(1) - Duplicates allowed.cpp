class RandomizedCollection {
public:
	/** Initialize your data structure here. */
	RandomizedCollection() {

	}

	/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
	bool insert(int val) {
		bool res = true;
		if (mp.count(val)) res = false;
		mp[val].push_back(stream.size());
		stream.push_back({ val,mp[val].size() - 1 });
		return res;
	}

	/** Removes a value from the collection. Returns true if the collection contained the specified element. */
	bool remove(int val) {
		if (!mp.count(val)) return false;
		int idx = mp[val].back();
		pair<int, int> backup = stream.back();

		stream[idx] = backup;
		stream.pop_back();

		mp[backup.first][backup.second] = idx;
		mp[val].pop_back();

		if (mp[val].empty()) mp.erase(val);
		return true;
	}

	/** Get a random element from the collection. */
	int getRandom() {
		return stream[rand() % stream.size()].first;
	}
private:
	vector<pair<int, int>> stream;
	unordered_map<int, vector<int>> mp;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */