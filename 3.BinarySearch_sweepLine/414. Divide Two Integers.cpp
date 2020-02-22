//414. Divide Two Integers
//
//1. while(res > factor) factor<<1, shift++
//2. res -= (factor>>1), factor = labs(divisor)
//3. count += (1 << (shift - 1))


class Solution {
public:
	/**
	 * @param dividend: the dividend
	 * @param divisor: the divisor
	 * @return: the result
	 */
	int divide(int dividend, int divisor) {
		// write your code here
		if (divisor == 0) return dividend > 0 ? INT_MAX : INT_MIN;
		if (dividend == 0) return 0;
		if (dividend == INT_MIN && divisor == -1) {
			return INT_MAX;
		}
		int neg = ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0));
		long res = labs(dividend), factor = labs(divisor);
		long shift = 0;
		long count = 0;
		while (res >= labs(divisor))
		{
			shift = 0;
			while (res >= factor)
			{
				factor = factor << 1;
				shift++;
			}
			res = (res - (factor >> 1));
			factor = labs(divisor);
			count += 1 << (shift - 1);
		}
		return neg == 0 ? count : -count;
	}
};