415. Valid Palindrome

class Solution {
public:
	/**
	 * @param s: A string
	 * @return: Whether the string is a valid palindrome
	 */
	bool isPalindrome(string& s) {
		// write your code here
		int left = 0, right = s.size();
		while (left < right)
		{
			while (left < right && !is_valid(s[left])) left++;
			while (left < right && !is_valid(s[right])) right--;
			if (tolower(s[left]) == tolower(s[right]))
			{
				left++; right--;
			}
			else return false;
		}
		return true;
	}

	bool is_valid(char c)
	{
		if (isalpha(c) || isdigit(c)) return true;
		return false;
	}
};