//1277. Water and Jug Problem
//return z % gcd(x, y) == 0
//gcd(x.y) = if (y % x == 0) return x, else return gcd(y % x, x)
//gcd(x, y) <=> gcd(y % x, x) <=> gcd(res, 0)


class Solution {
public:
	/**
	 * @param x: the given number x
	 * @param y: the given number y
	 * @param z: the given number z
	 * @return: whether it is possible to measure exactly z litres using these two jugs
	 */
	bool canMeasureWater(int x, int y, int z) {
		// Write your code here
		if (x > y)
		{
			int tmp = x;
			x = y;
			y = tmp;
		}
		int d = gcd(x, y);
		return z % d == 0;
	}

	int gcd(int x, int y)
	{
		if (y % x == 0) return x;
		else return gcd(y % x, x);
	}
};