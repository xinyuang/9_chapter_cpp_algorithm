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
#include <assert.h>

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

class distinctWindow {
private:
	vector<int> A;
	
public:
	distinctWindow(vector<int> arr)
	{
		A = arr;
	}

	int getDistinctWindowNumber()
	{
		unordered_map<int, int> mp;
		int count = 0;
		for (int i = 0; i < 3; i++)
		{
			mp[A[i]]++;
		}
		if (mp.size() == 3) count++;
		for (int i = 3; i < A.size(); i++)
		{
			mp[A[i - 3]]--;
			if (mp[A[i - 3]] == 0) mp.erase(A[i - 3]);
			mp[A[i]]++;
			if (mp.size() == 3) count++;
		}
		return count;
	}
};

int main() {

	vector<int> arr = { 1,2,3,4,5 };
	distinctWindow a = distinctWindow(arr);
	cout << a.getDistinctWindowNumber() << endl;
	int my = a.getDistinctWindowNumber();
	int res0 = 3;
	assert(my == res0);

	vector<int> arr1 = { 1,2,2,2,5 };
	distinctWindow b = distinctWindow(arr1);
	cout << b.getDistinctWindowNumber() << endl;
	int res1 = 0;
	int my1 = b.getDistinctWindowNumber();
	assert(my1 == res1);

	vector<int> arr2 = { 1,1,3,1,5 };
	distinctWindow c = distinctWindow(arr2);
	cout << c.getDistinctWindowNumber() << endl;
	int res2 = 1;
	int my2 = c.getDistinctWindowNumber();
	assert(my2 == res2);

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








