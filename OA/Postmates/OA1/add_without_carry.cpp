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

class Solution {
public:
	string add(string a, string b)
	{
		// ensure a.size() >= b.size()
		if (a.size() < b.size())
		{
			string tmp = a;
			a = b;
			b = tmp;
		}
		int diff = a.size() - b.size();
		string res = "";
		for (int i = 0; i < diff; i++) res.push_back(a[i]);
		for (int i = 0; i < b.size(); i++)
		{
			int a_number = a[diff++] - '0';
			int b_number = b[i] - '0';
			int sum = a_number + b_number;
			res += to_string(sum);
		}
		cout << res << endl;
		return res;
	}
};

int main() {

	Solution a = Solution();
	a.add("1199", "299");

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








