//589. Connecting Graph
//
//if rootA != rootB return not connected


class ConnectingGraph {
private:
	vector<int> father;
	int findFather(int a)
	{
		int cur = a;
		while (father[a] != a)
		{
			a = father[a];
		}

		while (father[cur] != a)
		{
			int tmp = father[cur];
			father[cur] = a;
			cur = tmp;
		}
		return a;
	}
public:
	/*
	* @param n: An integer
	*/ConnectingGraph(int n) {
	// do intialization if necessary
	vector<int> father = vector<int>(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		father[i] = i;
	}
	this->father = father;
}

	  /*
	   * @param a: An integer
	   * @param b: An integer
	   * @return: nothing
	   */
	  void connect(int a, int b) {
		  // write your code here
		  int root_a = findFather(a);
		  int root_b = findFather(b);
		  if (root_a != root_b)
		  {
			  father[root_b] = root_a;
		  }
	  }

	  /*
	   * @param a: An integer
	   * @param b: An integer
	   * @return: A boolean
	   */
	  bool query(int a, int b) {
		  // write your code here
		  int root_a = findFather(a);
		  int root_b = findFather(b);
		  return root_b == root_a;
	  }
};