#include <bitset>
class CountingBloomFilter {
public:
	class HashFunc {
	public:
		int cap;
		int seed;
		HashFunc(int c, int s) : cap(c), seed(s) {}
		int hash(string str)
		{
			int hashcode = -1;
			for (int i = 0; i < str.size(); i++)
			{
				hashcode = hashcode * seed + str[i];
				hashcode = hashcode % cap;
			}
			return hashcode;
		}
	};
	/*
	* @param k: An integer
	*/CountingBloomFilter(int k) {
	// do intialization if necessary
		this->k = k;
		for (int i = 0; i < k; i++)
		{
			filter.push_back(new HashFunc(100000 + i, 2 * i + 3));
		}
		setbit.resize(100000 + k, 0);
	}

	/*
	 * @param word: A string
	 * @return: nothing
	 */
	void add(string& word) {
		// write your code here
		for (int i = 0; i < k; i++)
		{
			int idx = filter[i]->hash(word);
			setbit[idx]++;
		}
	}

	/*
	 * @param word: A string
	 * @return: nothing
	 */
	void remove(string& word) {
		// write your code here
		for (int i = 0; i < k; i++)
		{
			int idx = filter[i]->hash(word);
			setbit[idx]--;
		}
	}

	/*
	 * @param word: A string
	 * @return: True if contains word
	 */
	bool contains(string& word) {
		// write your code here
		for (int i = 0; i < k; i++)
		{
			int idx = filter[i]->hash(word);
			if (setbit[idx] <= 0) return false;
		}
		return true;
	}
private:
	vector<int> setbit;
	vector<HashFunc*> filter;
	int k;
};