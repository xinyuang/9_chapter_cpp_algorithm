// Minimum Window Substring

//  asdbfbgbwb  adb   mp<char,int> char - count (still need ? chars to satisfy requirement)
//  . ..
//  i is right ptr, left moves to right util count < tar_len
//  expand -> shrink ->expand ->shrink
class Solution {
public:
	/**
	 * @param source : A string
	 * @param target: A string
	 * @return: A string denote the minimum window, return "" if there is no such a string
	 */
	string minWindow(string& source, string& target) {
		// write your code here
		unordered_map<char, int> mp; // char, count
		int tar_len = target.size();
		int count = 0;
		int left_ptr = 0;
		string res = "";
		int res_len = source.size() + 1;
		for (int i = 0; i < target.size(); i++)
		{
			mp[target[i]]++;
		}
		for (int i = 0; i < source.size(); i++)
		{
			if (--mp[source[i]] >= 0)
			{
				count++;
			}
			while (count == tar_len)
			{
				int len = i - left_ptr + 1;
				if (len < res_len)
				{
					res_len = len;
					res = source.substr(left_ptr, len);
				}
				if (++mp[source[left_ptr]] > 0) count--;
				left_ptr++;
			}
		}
		return res;
	}
};