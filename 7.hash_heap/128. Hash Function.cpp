class Solution {
public:
	/**
	 * @param key: A string you should hash
	 * @param HASH_SIZE: An integer
	 * @return: An integer
	 */
	int hashCode(string& key, int HASH_SIZE) {
		// write your code here
		long res = 0;
		for (int i = 0; i < key.size(); i++)
		{
			res = (res * 33 + key[i]) % HASH_SIZE;
		}
		return res;
	}
};