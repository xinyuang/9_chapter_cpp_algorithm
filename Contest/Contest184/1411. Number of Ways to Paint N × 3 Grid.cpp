//1411. Number of Ways to Paint N × 3 Grid
//initial step x(2 colors pattern) = 6, y(3 colors pattern) = 6
//x' = 3x + 2y
//y' = 2x + 2y

class Solution {
public:
	int numOfWays(int n) {
		long x = 6, y = 6;
		long mod = pow(10, 9) + 7;
		for (int i = 1; i < n; i++)
		{
			long xx = (3 * x) % mod + (2 * y) % mod;
			long yy = (2 * x) % mod + (2 * y) % mod;
			x = xx % mod;
			y = yy % mod;
		}
		long sum = x + y;
		sum = sum % mod;
		return (int)sum;
	}
};