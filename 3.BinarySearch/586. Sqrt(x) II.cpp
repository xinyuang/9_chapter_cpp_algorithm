// Sqrt(x) II

// binary search
class Solution {
public:
	/**
	 * @param x: a double
	 * @return: the square root of x
	 */
	double sqrt(double x) {
		// write your code here
		double sigma = pow(0.1, 14);
		double delta = 1;
		double left = 0;
		double right = 1;
		if (x > 1) right = x;
		double mid = x;
		while (abs(delta) > sigma)
		{
			mid = (right - left) / 2 + left;
			delta = mid * mid - x;
			if (delta < 0) left = mid;
			else right = mid;
		}
		return mid;
	}
};

// Newton's method
class Solution {
public:
	/**
	 * @param x: a double
	 * @return: the square root of x
	 */
	double sqrt(double x) {
		// write your code here
		double sigma = pow(0.1, 13);
		double delta = 1;
		double res = x;
		while (delta > sigma)
		{
			res = (res + x / res) * 0.5;
			delta = abs(x - res * res);
		}
		return res;
	}
};

