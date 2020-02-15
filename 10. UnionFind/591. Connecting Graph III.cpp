//591. Connecting Graph III
//if (root_a != root_b) number = number - 1

class ConnectingGraph3 {
private:
	int count;
	vector<int> father;
public:
	/**
	 * @param a: An integer
	 * @param b: An integer
	 * @return: nothing
	 */
	ConnectingGraph3(int n) {
		// initialize your data structure here.
		count = n;
		for (int i = 0; i < n; i++) father.push_back(i);
	}
	void connect(int a, int b) {
		// write your code here
		int rootA = findRoot(a, father);
		int rootB = findRoot(b, father);
		if (rootA != rootB)
		{
			father[rootB] = rootA;
			count--;
		}
	}

	/**
	 * @return: An integer
	 */
	int query() {
		// write your code here
		return count;
	}

	int findRoot(int x, vector<int>& father)
	{
		while (x != father[x])
		{
			x = father[x];
		}
		return x;
	}
};