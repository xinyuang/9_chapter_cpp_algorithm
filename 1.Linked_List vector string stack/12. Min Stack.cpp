// min Stack
// minStack, stk monotonic decrease
class MinStack {
public:
	MinStack() {
		// do intialization if necessary
	}

	/*
	 * @param number: An integer
	 * @return: nothing
	 */
	void push(int number) {
		// write your code here
		int x = number;
		stk.push(x);
		if (minStack.empty()) minStack.push(x);
		else
		{
			if (minStack.top() >= x) minStack.push(x);
		}
	}

	/*
	 * @return: An integer
	 */
	int pop() {
		// write your code here
		if (stk.empty() || minStack.empty()) return -1;
		int cur = stk.top(); stk.pop();
		if (cur == minStack.top()) minStack.pop();
		return cur;
	}

	/*
	 * @return: An integer
	 */
	int min() {
		// write your code here
		if (minStack.empty()) return -1;
		return minStack.top();

	}

private:
	stack<int> stk;
	stack<int> minStack;
};