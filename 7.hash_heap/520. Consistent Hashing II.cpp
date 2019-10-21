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
		solution.circle_size = n;
		solution.points = k;
		return solution;
	}

	/*
	 * @param machine_id: An integer
	 * @return: a list of shard ids
	 */
	vector<int> addMachine(int machine_id) {
		// write your code here
		int hashcode = rand() % circle_size;
		int count = 0;
		vector<int> res;
		while (count < points)
		{
			hashcode = rand() % circle_size;
			if (!mp.count(hashcode))
			{
				mp[hashcode] = machine_id;
				count++;
				res.push_back(hashcode);
			}
		}
		return res;
	}

	/*
	 * @param hashcode: An integer
	 * @return: A machine id
	 */
	int getMachineIdByHashCode(int hashcode) {
		// write your code here
		auto it = mp.lower_bound(hashcode);
		if (it == mp.end()) return mp.begin()->second;
		return it->second;
	}

private:
	int circle_size;
	int points;
	map<int, int> mp;  // hashcode - machine_id
};