//601. Flatten 2D Vector
//stack store reverse values

class Vector2D {
private:
	stack<int> stk;
public:
	Vector2D(vector<vector<int>>& vec2d) {
		// Initialize your data structure here
		for (int i = vec2d.size() - 1; i >= 0; i--)
		{
			for (int j = vec2d[i].size() - 1; j >= 0; j--)
			{
				stk.push(vec2d[i][j]);
			}
		}
	}

	int next() {
		// Write your code here
		int res = stk.top(); stk.pop();
		return res;
	}

	bool hasNext() {
		// Write your code here
		return !stk.empty();
	}
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
