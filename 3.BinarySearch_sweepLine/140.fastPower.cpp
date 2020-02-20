// Fast Power
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
		if (n == 0) return 1 % b;
		if (a == 0) return 0;
		long res = power(a, b, n);
		return res;
	}

	long power(long a, long b, int n)
	{
		if (n == 1) return a % b;
		long sub = power(a, b, n / 2);
		sub = sub * sub % b;
		if (n % 2 == 0) return (sub % b);
		else return sub * (a % b) % b;
	}
};

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