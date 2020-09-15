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
private:
public:
	int goodTouple(vector<int> arr)
	{
		int count = 0;
		unordered_map<int, int> mp;
		for (int i = 0; i < 3; i++)
		{
			mp[arr[i]]++;
		}
		if (mp.size() == 2) count++;
		for (int i = 3; i < arr.size(); i++)
		{
			mp[arr[i - 3]]--;
			if (mp[arr[i - 3]] == 0) mp.erase(arr[i - 3]);
			mp[arr[i]]++;
			if (mp.size() == 2) count++;
		}
		cout << count << endl;
		return count;
	}
};

int main() {

	solution s = solution();
	s.goodTouple({ 1,2,2,3,4,5,6,6 });

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








