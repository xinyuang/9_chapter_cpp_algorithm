// 1246. Longest Repeating Character Replacement

class Solution {
public:
    /**
     * @param s: a string
     * @param k: a integer
     * @return: return a integer
     */
    int characterReplacement(string &s, int k) {
        // write your code here
        vector<int> hash(26,0);
        int left = 0;
        int longest = 0;
        for(int i = 0; i < s.size(); i++)
        {
            hash[s[i] - 'A']++;
            while(!is_valid(hash,k))
            {
                hash[s[left] - 'A']--;
                left++;
            }
            longest = max(longest, i - left + 1);
        }
        return longest;
    }
    
    //  if max(hash[i]) + k >= sum(hash[i]), can generate one repeating string
    bool is_valid(vector<int>& hash, int k)
    {
        int longest = 0;
        int ttl = 0;
        for(int i = 0; i < 26; i++)
        {
            ttl += hash[i];
            longest = max(longest,hash[i]);
        }
        return longest + k >= ttl;
    }
};


class Solution {
public:
	/**
	 * @param s: a string
	 * @param k: a integer
	 * @return: return a integer
	 */
	int characterReplacement(string& s, int k) {
		// write your code here
		vector<int> bucket(26, 0);
		int max_len = 0;
		for (int i = 0, j = 0; i < s.size(); i++)
		{
			bucket[s[i] - 'A']++;
			while (!is_valid(bucket, k))
			{
				bucket[s[j++] - 'A']--;
			}
			max_len = max(max_len, i - j + 1);
		}
		return max_len;
	}

	bool is_valid(vector<int>& bucket, int k)
	{
		int len = 0;
		int longest = 0;
		for (int i = 0; i < 26; i++)
		{
			len += bucket[i];
			longest = max(longest, bucket[i]);
		}
		return longest + k >= len;
	}
};