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
	void XYelimilate(vector<int> arr)
	{
		stack<int> stk;
		int count = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			if (stk.empty() || stk.top() != arr[i])
			{
				stk.push(arr[i]);
			}
			else
			{
				stk.pop();
				count++;
			}
		}
		if (count % 2 == 0) cout << "Y win" << endl;
		else cout << "X win" << endl;
	}
};

int main() {

	solution s = solution();
	s.XYelimilate({ 1,1,2,2 });
	s.XYelimilate({ 1,1,3,2,2 });
	s.XYelimilate({ 1,1,2,3,2 });
	s.XYelimilate({ 1,1,2,2,1,1});


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








