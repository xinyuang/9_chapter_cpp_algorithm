//367. Expression Tree Build
//1. convert to reverse polish notation(RPN), use stack<TreeNode*> to build Tree
//2. cur = new Node(RPN[i]) if is operator, pop 2 element to build cur->left, cur->right
//3. if is number, push to stack
//4. if !stack.empty() return stack.top() else return 0

/**
 * Definition of ExpressionTreeNode:
 * class ExpressionTreeNode {
 * public:
 *     string symbol;
 *     ExpressionTreeNode *left, *right;
 *     ExpressionTreeNode(string symbol) {
 *         this->symbol = symbol;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


	class Solution {
	public:
		/*
		 * @param expression: A string array
		 * @return: The root of expression tree
		 */
		ExpressionTreeNode* build(vector<string>& expression) {
			// write your code here
			vector<string> RPN = genRPN(expression);
			if (RPN.size() == 0) return nullptr;
			stack<ExpressionTreeNode*> stk;
			for (int i = 0; i < RPN.size(); i++)
			{
				ExpressionTreeNode* cur = new ExpressionTreeNode(RPN[i]);
				if (is_operator(RPN[i])) {
					ExpressionTreeNode* right = stk.top(); stk.pop();
					ExpressionTreeNode* left = stk.top(); stk.pop();
					cur->left = left;
					cur->right = right;
				}
				stk.push(cur);
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
				else if (str[i] == ")") {
					while (stk.top() != "(")
					{
						res.push_back(stk.top());
						stk.pop();
					}
					stk.pop();
				}
				else if (is_operator(str[i])) {
					while (!stk.empty() && level(stk.top()) >= level(str[i]))
					{
						res.push_back(stk.top());
						stk.pop();
					}
					stk.push(str[i]);
				}
				else {
					stk.push(str[i]);
				}
			}
			while (!stk.empty())
			{
				res.push_back(stk.top());
				stk.pop();
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
