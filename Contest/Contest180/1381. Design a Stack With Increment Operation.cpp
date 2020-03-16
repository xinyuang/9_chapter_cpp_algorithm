//1381. Design a Stack With Increment Operation
//Design a stack which supports the following operations.
//
//Implement the CustomStack class :
//
//	CustomStack(int maxSize) Initializes the object with maxSize which is the maximum number of elements in the stack or do nothing if the stack reached the maxSize.
//	void push(int x) Adds x to the top of the stack if the stack hasn't reached the maxSize.
//	int pop() Pops and returns the top of stack or -1 if the stack is empty.
//	void inc(int k, int val) Increments the bottom k elements of the stack by val.If there are less than k elements in the stack, just increment all the elements in the stack.



class CustomStack {
private:
	stack<int> stk1;
	stack<int> stk2;
	int cap;
public:
	CustomStack(int maxSize) {
		cap = maxSize;
	}

	void push(int x) {
		if (stk1.size() >= cap) return;
		stk1.push(x);
	}

	int pop() {
		if (stk1.empty()) return -1;
		int res = stk1.top();
		stk1.pop();
		return res;
	}

	void increment(int k, int val) {
		while (!stk1.empty())
		{
			int cur = stk1.top(); stk1.pop();
			stk2.push(cur);
		}
		for (int i = 0; i < k; i++)
		{
			if (stk2.empty()) break;
			int cur = stk2.top(); stk2.pop();
			stk1.push(cur + val);
		}
		while (!stk2.empty())
		{
			int cur = stk2.top(); stk2.pop();
			stk1.push(cur);
		}
	}
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */