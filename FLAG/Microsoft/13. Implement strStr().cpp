//13. Implement strStr()
//Z algorithm

class Solution {
public:
	/**
	 * @param source:
	 * @param target:
	 * @return: return the index
	 */
	int strStr(string& source, string& target) {
		// Write your code here
		if (target.size() == 0) return 0;
		source = target + "$" + source;
		int t_len = target.size();
		vector<int> z(source.size(), 0);
		int L = 0, R = 0;
		for (int i = 1; i < source.size(); i++)
		{
			if (i > R)
			{
				L = R = i;
				while (R < source.size() && source[R] == source[R - L]) R++;
				z[i] = R - L; R--;
			}
			else
			{
				int k = i - L;
				int len = R - i + 1;
				if (z[k] < len) z[i] = z[k];
				else
				{
					L = i;
					while (R < source.size() && source[R] == source[R - L]) R++;
					z[i] = R - L; R--;
				}
			}
			if (z[i] == t_len) return i - t_len - 1;
		}
		return -1;
	}
};

class Solution {
public:
	/**
	 * @param source:
	 * @param target:
	 * @return: return the index
	 */
	int strStr(string& source, string& target) {
		// Write your code here
		if (target.size() == 0) return 0;
		int ptr = 0;
		for (int i = 0; i < source.size(); i++)
		{
			ptr = i;
			while (ptr - i < target.size() && source[ptr] == target[ptr - i])
			{
				ptr++;
			}
			if (ptr - i == target.size()) return i;
		}
		return -1;
	}
};