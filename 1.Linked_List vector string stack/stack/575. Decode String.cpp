//575. Decode String
//1. stack<int> number, stack<string> chars
//2. if s[i] == '[' number.push(count), chars.push(str)
//3. if s[i] == ']' flat pop ori top, push(ori + flat str)
//4. reverse the string res

class Solution {
public:
	/**
	 * @param s: an expression includes numbers, letters and brackets
	 * @return: a string
	 */
	string expressionExpand(string& s) {
		// write your code here
		int ptr = 0;
		stack<char> stk;
		stack<int> factor;
		int times = 0;
		while (ptr < s.size())
		{
			if (s[ptr] == '[') {
				if (ptr - 1 < 0 || !isdigit(s[ptr - 1])) {
					times = 1;
					factor.push(times);
				}
				stk.push(s[ptr++]);
			}
			else if (isalpha(s[ptr])) {
				stk.push(s[ptr++]);
			}
			else if (isdigit(s[ptr])) {
				string count = "";
				while (isdigit(s[ptr])) {
					count.push_back(s[ptr++]);
				}
				times = stoi(count);
				factor.push(times);
			}
			else if (s[ptr] == ']') {
				ptr++;
				string tmp = "";
				while (stk.top() != '[') {
					tmp.push_back(stk.top());
					stk.pop();
				}
				stk.pop();
				int cur_time = factor.top(); factor.pop();
				for (int i = 0; i < cur_time; i++)
				{
					for (int j = tmp.size() - 1; j >= 0; j--)
					{
						stk.push(tmp[j]);
					}
				}
			}
		}
		string res = "";
		while (!stk.empty())
		{
			res.push_back(stk.top()); stk.pop();
		}
		reverse(res.begin(), res.end());
		return res;
	}
};