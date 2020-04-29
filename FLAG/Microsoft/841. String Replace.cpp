//841. String Replace
//hashcode[r] = hashcode[l, r] + hashcode[1, l - 1] * base[r - l + 1]


class Solution {
public:
	/**
	 * @param a: The A array
	 * @param b: The B array
	 * @param s: The S string
	 * @return: The answer
	 */
	string stringReplace(vector<string>& a, vector<string>& b, string& s) {
		// Write your code here
		int i = 0;
		while (i < s.size())
		{
			int next = -1;
			string replace = "";
			for (int j = 0; j < a.size(); j++)
			{
				if (s.substr(i, a[j].size()) == a[j])
				{
					int farest = i + a[j].size() - 1;
					if (farest > next)
					{
						next = farest;
						replace = b[j];
					}
				}
			}
			if (next != -1)
			{
				for (int k = 0; k < replace.size(); k++)
				{
					s[i + k] = replace[k];
				}
				i = i + replace.size();
			}
			else
			{
				i++;
			}
		}
		return s;
	}
};


class Solution {
public:
	/**
	 * @param a: The A array
	 * @param b: The B array
	 * @param s: The S string
	 * @return: The answer
	 */
	string stringReplace(vector<string>& a, vector<string>& b, string& s) {
		// Write your code here
		vector<int> ahash;
		vector<int> shash;
		vector<int> base;
		int seed = 33;
		int mod = pow(10, 9) + 7;
		int max_len = 0;
		for (int i = 0; i < a.size(); i++)
		{
			int res = 0;
			max_len = max(max_len, (int)a[i].size());
			for (int j = 0; j < a[i].size(); j++)
			{
				res = ((long long)res * seed + a[i][j] - 'a') % mod;
			}
			ahash.push_back(res);

		}
		int res = 0;
		for (int i = 0; i < s.size(); i++)
		{
			res = ((long long)res * seed + s[i] - 'a') % mod;
			shash.push_back(res);
		}
		max_len = max(max_len, (int)s.size());
		res = 1;
		base.push_back(res);
		for (int i = 1; i < max_len; i++)
		{
			res = ((long long)res * seed) % mod;
			base.push_back(res);
		}
		for (int i = 0; i < s.size(); i++)
		{
			int next = -1;
			int b_idx = -1;
			for (int j = 0; j < a.size(); j++)
			{
				int len = a[j].size();
				int l = i;
				int r = i + len - 1;
				if (r >= s.size()) continue;
				int shashValue = (shash[r] - (long long)shash[l - 1] * base[r - l + 1] % mod + mod) % mod;
				int ahashValue = ahash[j];
				if (shashValue == ahashValue && next < r)
				{
					next = r;
					b_idx = j;
				}
			}
			if (next != -1)
			{
				for (int k = 0; k < b[b_idx].size(); k++)
				{
					s[i + k] = b[b_idx][k];
				}
				i = next;
			}
		}
		return s;
	}
};