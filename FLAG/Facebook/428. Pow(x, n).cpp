//428. Pow(x, n)
//1.  while loop, only n == odd, evalueate the value else x *= x

class Solution {
public:
	/**
	 * @param x: the base number
	 * @param n: the power number
	 * @return: the result
	 */
	double myPow(double x, int n) {
		// write your code here
		if (n == 0) return 1;
		if (n == 1) return x;
		if (n < 0)
		{
			if (n == INT_MIN && x > 1) return 0;
			x = 1 / x;
			n *= -1;
		}
		double res = 1;
		while (n > 0)
		{
			if (n % 2 != 0) res *= x;
			n = n / 2;
			x *= x;
		}
		return res;
	}
};

class Solution {
public:
	/**
	 * @param x: the base number
	 * @param n: the power number
	 * @return: the result
	 */
	double myPow(double x, int n) {
		// write your code here
		if (n == 0) return 1;
		if (n == 1) return x;
		if (n < 0)
		{
			if (n == INT_MIN && x > 1) return 0;
			n *= -1;
			x = 1 / x;
		}
		double xx = myPow(x, n / 2);
		if (xx < pow(10, -10)) return 0;
		if (n % 2 == 0)return xx * xx;
		else return xx * xx * x;
	}
};