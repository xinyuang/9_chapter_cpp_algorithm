//1390. Four Divisors
//1. for loop from 2 to sqrt(n), if two divisor are both prime, it has 4 divisor
//2. if one divisor is prime(k) and the other is equal to k * k, it has 4 divisor

class Solution {
public:
	int sumFourDivisors(vector<int>& nums) {
		int sum = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			int left = nums[i];
			int count = 0;
			for (int k = 2; k < sqrt(left); k++)
			{
				if (left % k == 0)
				{
					if (isPrime(k) && isPrime(left / k))
						sum += (1 + nums[i] + k + left / k);
					if (isPrime(k) && k * k * k == left)
						sum += (1 + nums[i] + k + left / k);
					break;
				}
			}
		}
		return sum;
	}

	bool isPrime(int n)
	{
		for (int i = 2; i <= sqrt(n); i++)
		{
			if (n % i == 0) return false;
		}
		return true;
	}
};