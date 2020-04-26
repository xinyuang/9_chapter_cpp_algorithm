//728. Three Distinct Factors
//1. get sqrt
//2. check prime

class Solution {
public:
	/**
	 * @param n: the given number
	 * @return:  return true if it has exactly three distinct factors, otherwise false
	 */
	bool isThreeDisctFactors(long long n) {
		// write your code here
		long factor = getSqrt(n);
		if (factor * factor != n) return false;
		return isPrime(factor, n);
	}

	double getSqrt(long long n)
	{
		long long left = 1, right = pow(2, 32);
		while (left + 1 < right)
		{
			long long mid = (right - left) / 2 + left;
			if (mid * mid <= n) left = mid;
			else right = mid;
		}
		if (abs(left * left - n) < abs(right * right - n)) return left;
		else return right;
	}

	// double getSqrt(double x) {
	//     // write your code here
	//     double sigma = pow(0.1,13);
	//     double delta = 1;
	//     double x_new = x;
	//     double last_x = 1;
	//     while(abs(last_x - x_new) > sigma)
	//     {
	//         last_x = x_new;
	//         x_new = 0.5 * x_new + x * 0.5 / x_new;
	//     }
	//     return x_new;
	// }

	bool isPrime(long factor, long long n)
	{
		if (factor <= 3) return true;
		if (factor % 2 == 0 || factor % 3 == 0) return false;
		for (int i = 5; i * i <= factor; i += 6)
		{
			if (n % i == 0 || n % (i + 2) == 0) return false;
		}
		return true;
	}
};