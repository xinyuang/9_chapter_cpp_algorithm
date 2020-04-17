//368. Expression Evaluation
//Evaluate Reverse Polish Notation

class Solution {
public:
	/**
	 * @param expression: a list of strings
	 * @return: an integer
	 */
	int evaluateExpression(vector<string>& expression) {
		// write your code here
		vector<string> RPN = genRPN(expression);
		if (RPN.size() == 0) return 0;
		int res = 0;
		stack<int> stk;
		for (int i = 0; i < RPN.size(); i++)
		{
			if (is_operator(RPN[i])) {
				int cur = 0;
				int right = stk.top(); stk.pop();
				int left = stk.top(); stk.pop();
				if (RPN[i] == "+") cur = left + right;
				if (RPN[i] == "-") cur = left - right;
				if (RPN[i] == "*") cur = left * right;
				if (RPN[i] == "/") cur = left / right;
				stk.push(cur);
			}
			else
			{
				stk.push(stoi(RPN[i]));
			}
		}
		return stk.top();
	}

	vector<string> genRPN(vector<string>& str)
	{
		stack<string> stk;
		vector<string> res;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == "(") stk.push(str[i]);
			else if (str[i] == ")")
			{
				while (!stk.empty() && stk.top() != "(")
				{
					res.push_back(stk.top()); stk.pop();
				}
				stk.pop();
			}
			else if (is_operator(str[i]))
			{
				while (!stk.empty() && level(stk.top()) >= level(str[i]))
				{
					res.push_back(stk.top()); stk.pop();
				}
				stk.push(str[i]);
			}
			else stk.push(str[i]);
		}
		while (!stk.empty())
		{
			res.push_back(stk.top()); stk.pop();
		}
		return res;
	}

	int level(string s)
	{
		if (s == "(") return 0;
		if (s == "+" || s == "-") return 1;
		if (s == "*" || s == "/") return 2;
		return 3;
	}

	bool is_operator(string s)
	{
		if (s == "+" || s == "-" || s == "*" || s == "/") return true;
		return false;
	}
};