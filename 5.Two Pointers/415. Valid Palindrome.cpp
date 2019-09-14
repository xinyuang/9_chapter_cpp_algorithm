class Solution {
public:
	/**
	 * @param s: A string
	 * @return: Whether the string is a valid palindrome
	 */
	bool isPalindrome(string& s) {
		// write your code here
		int left = 0, right = s.size() - 1;
		while (left < right)
		{
			while (not_valid(s[left])) left++;
			while (not_valid(s[right])) right--;
			if (left >= right) return true;
			if (is_equal(s[left], s[right]))
			{
				left++;
				right--;
			}
			else return false;
		}
		return true;
	}

	bool not_valid(char& c)
	{
		if (c >= 'A' && c <= 'z') return false;
		if (isdigit(c)) return false;
		return true;
	}

	bool is_equal(char a, char b)
	{
		if (a == b || toupper(a) == b || a == toupper(b)) return true;
		return false;
	}
};