class Solution {
public:
	/**
	 * @param a: A 32bit integer
	 * @param b: A 32bit integer
	 * @param n: A 32bit integer
	 * @return: An integer
	 */
	int fastPower(int a, int b, int n) {
		// write your code here
		if (a == 0) return 0;
		if (n == 0) return 1 % b;
		if (n == 1) return a % b;

		long res = 1;
		long base = a;
		while (n != 0)
		{
			if (n % 2 != 0) res = (res * base % b);
			base = (base * base % b);
			n /= 2;
		}
		return res;
	}
};