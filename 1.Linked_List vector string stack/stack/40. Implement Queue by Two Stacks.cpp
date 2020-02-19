//40. Implement Queue by Two Stacks
//1. stackA, stackB
//2. push to B, when A is empty, move to A, use A to pop, top.

class MyQueue {
private:
	stack<int> stk1;
	stack<int> stk2;
public:
	MyQueue() {
		// do intialization if necessary
		while (!stk1.empty()) stk1.pop();
		while (!stk2.empty()) stk2.pop();
	}

	/*
	 * @param element: An integer
	 * @return: nothing
	 */
	void push(int element) {
		// write your code here
		stk1.push(element);
	}

	/*
	 * @return: An integer
	 */
	int pop() {
		// write your code here
		if (stk2.empty())
		{
			while (!stk1.empty())
			{
				stk2.push(stk1.top());
				stk1.pop();
			}
		}
		if (stk2.empty()) return -1;
		int res = stk2.top(); stk2.pop();
		return res;
	}

	/*
	 * @return: An integer
	 */
	int top() {
		// write your code here
		if (stk2.empty()) {
			while (!stk1.empty())
			{
				stk2.push(stk1.top());
				stk1.pop();
			}
		}
		return stk2.top();
	}
};