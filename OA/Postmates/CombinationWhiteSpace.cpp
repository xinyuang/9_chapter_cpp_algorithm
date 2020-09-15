//// 9_chapter_cpp_algorithm.cpp : Defines the entry point for the application.
////
//
#include "9_chapter_cpp_algorithm.h"
#include <iostream>
#include <time.h> 
#include <ppl.h>
#include <iomanip>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include "assert.h"

using namespace std;

struct ooops : std::exception {
	const char* what() const noexcept { return "Ooops!\n"; }
};

class node {
public:
	int key;
	int value;
	node(int k, int v)
	{
		this->key = k;
		this->value = v;
	}
};

class solution {
private:
public:
	int spaceNumber(int n, int limit, int m, string s)
	{
		int mod = pow(10, m);
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		int len = (to_string(limit)).size();
		for (int i = 1; i <= n; i++)
		{
			int count = 0;
			if (i - len >= 0 && (stoi(s.substr(i - len, len)) <= limit))
			{
				dp[i] = dp[i - len];
			}
			for (int j = max(0, i - len + 1); j < i; j++)
			{
				
				dp[i] += (dp[j]%mod);
			}
			dp[i] = dp[i] % mod;
		}
		return dp.back();
	}
};

int main() {

	solution s = solution();
	cout << s.spaceNumber(5, 123, 8, "12345") << endl;
	cout << s.spaceNumber(7, 1234567, 9, "1234567") << endl;

	//int8_t a = 200;
	//uint8_t b = 100;
	//cout << bool(a > b) << endl;
	//node* n = new node(1, 2);
	//try {
		//if(1) throw ooops();
	//}
	//catch (std::exception& ex) {
	//	std::cout << ex.what();
	//}
	//int x = 5, y = 2;
	//cout << x & y << endl;
	//cout << 1 << endl;
	return 0;
}








