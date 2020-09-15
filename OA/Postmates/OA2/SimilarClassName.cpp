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
	bool similarName(string a, string b) {
		unordered_map<char, int> mp1;
		unordered_map<char, int> mp2;
		for (int i = 0; i < a.size(); i++)
		{
			mp1[a[i]]++;
		}
		for (int i = 0; i < b.size(); i++)
		{
			mp2[b[i]]++;
		}
		if (mp1.size() != mp2.size()) return false;
		unordered_map<string, int> mp;
		multiset<int> st1;
		multiset<int> st2;
		for (auto e : mp1)
		{
			if (!mp2.count(e.first)) return false;
			st1.insert(e.second);
		}
		for (auto e : mp2)
		{
			st2.insert(e.second);
		}
		return st1 == st2;
	}
};

int main() {

	solution s = solution();
	multiset<int> st1 = { 1,1,2 };
	multiset<int> st2 = { 2,1,1 };
	cout << bool(st1 == st2) << endl;
	cout << s.similarName("abbczzz", "babzzcz") << endl;
	cout << s.similarName("abcbdb", "bdbcca") << endl;

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








