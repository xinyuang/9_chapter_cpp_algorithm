//1502. Prime Palindrome
//1. while not palindrome n++
//2. while not prime, get next palindrome
//3. next palindrom if odd, mid < 9, n += pow(10, mid), even n += pow(10, i) + pow(10, i + 1)
//4. if all 9999...n += 2

class Solution {
public:
	/**
	 * @param N: the input
	 * @return: the answer
	 */
	int primePalindrome(int N) {
		// Write your code here.
		while (!isPal(N)) N++;
		while (!isPrime(N)) N = nextPal(N);
		return N;
	}

	bool isPal(int n)
	{
		string s = to_string(n);
		int left = 0, right = s.size() - 1;
		while (left < right)
		{
			if (s[left] != s[right]) return false;
			left++; right--;
		}
		return true;
	}

	bool isPrime(int n)
	{
		int mid = sqrt(n);
		for (int i = 2; i <= mid; i++)
		{
			if (n % i == 0) return false;
		}
		return true;
	}

	int nextPal(int n)
	{
		int len = 0;
		while (pow(10, len) <= n) len++;
		int mid = (len - 1) / 2;
		for (int i = mid; i >= 0; i--)
		{
			int cur = (n / (int)pow(10, i)) % 10;
			if (cur < 9)
			{
				if (len % 2 == 1 && i == mid) return n + pow(10, mid);
				return n + pow(10, i) + pow(10, i + 1);
			}
		}
		return n + 2;
	}
};