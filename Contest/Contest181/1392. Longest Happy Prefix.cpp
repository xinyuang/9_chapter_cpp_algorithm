//1392. Longest Happy Prefix
//1. Z algorithm, L, R is the boundery of the Z box, where contains longest substr same as prefix
//2. array Z, where Z[i] means the longest length that s.substr(i, len) = s.substr(0, len)
//3. for loop i, if i < R, while loop to check Z[i] = R - L
//4. if i > R, k = i - L, if Z[k] < R - i + 1, Z[i] = Z[k], else L = i, while loop to check Z[i] = R - L

class Solution {
public:
	string longestPrefix(string s) {
		vector<int> Z(s.size(), 0);
		int L = 0, R = 0;
		for (int i = 1; i < s.size(); i++)
		{
			if (i > R)
			{
				L = R = i;
				while (R < s.size() && s[R] == s[R - L]) R++;
				Z[i] = R - L; R--;
			}
			else {
				int k = i - L;
				if (Z[k] < R - i + 1) Z[i] = Z[k];
				else
				{
					L = i;
					while (R < s.size() && s[R] == s[R - L]) R++;
					Z[i] = R - L; R--;
				}
			}
			if (Z[i] + i == s.size()) return s.substr(0, Z[i]);
		}
		return "";
	}
};
