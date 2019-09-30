//520. Consistent Hashing II

class Solution {
public:
	/*
	 * @param n: a positive integer
	 * @param k: a positive integer
	 * @return: a Solution object
	 */
	static Solution create(int n, int k) {
		// Write your code here
		Solution solution = Solution();
		solution.n = n;
		solution.k = k;
		return solution;
	}

	/*
	 * @param machine_id: An integer
	 * @return: a list of shard ids
	 */
	vector<int> addMachine(int machine_id) {
		// write your code here
		vector<int> res;
		for (int i = 0; i < k; i++)
		{
			int idx = rand() % n;
			while (ids.count(idx))
			{
				idx = rand() % n;
			}
			ids.insert(idx);
			shards[idx] = machine_id;
			res.push_back(idx);
		}
		sort(res.begin(), res.end());
		return res;
	}

	/*
	 * @param hashcode: An integer
	 * @return: A machine id
	 */
	int getMachineIdByHashCode(int hashcode) {
		// write your code here
		map<int, int>::iterator it = shards.lower_bound(hashcode);
		if (it == shards.end())
		{
			return shards.begin()->second;
		}
		else
		{
			return it->second;
		}
	}
private:
	int n;
	int k;
	map<int, int> shards;
	unordered_set<int> ids;
};