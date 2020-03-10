//1374. Generate a String With Characters That Have Odd Counts
//
//	Given an integer n, return a string with n characters such that each character in such string occurs an odd number of times.
//
//	The returned string must contain only lowercase English letters.If there are multiples valid strings, return any of them.
//
class Solution {
public:
	string generateTheString(int n) {
		int res = n;
		string return_str = "";
		int count = 0;
		while (res >= 0)
		{
			int new_res = res / 2;
			int tar = res - new_res;
			count++;
			if (tar % 2 == 0)
			{
				new_res = new_res - 1;
				tar = tar + 1;
			}
			for (int i = 0; i < tar; i++)
			{
				return_str.push_back('a' + count);
			}
			res = new_res;
			if (res == 0) break;
		}

		return return_str;
	}
};