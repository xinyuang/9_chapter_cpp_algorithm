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

class solution {
public:
	int matchPattern(string a, string p)
	{
		unordered_set<char> V = { 'a','e','i','o','u' };
		string mask = "";
		for (int i = 0; i < a.size(); i++)
		{
			if (V.count(a[i])) mask.push_back('0');
			else mask.push_back('1');
		}
		int count = 0;
		for (int i = 0; i <= mask.size() - p.size(); i++)
		{
			if (mask.substr(i, p.size()) == p) count++;
		}
		cout << count << endl;
		return count;
	}
};

int main() {

	solution a = solution();
	a.matchPattern("ataata", "010");

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








