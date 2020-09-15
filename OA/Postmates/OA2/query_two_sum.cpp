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
	vector<int> a;
	vector<int> b;
	unordered_map<int, int> mp;
public:
	void init(vector<int>& a_arr, vector<int>& b_arr)
	{
		a = a_arr;
		b = b_arr;
		for (int i = 0; i < b.size(); i++)
		{
			mp[b[i]]++;
		}
	}

	vector<int> query(vector<vector<int>> q_list)
	{
		vector<int> res;
		for (int i = 0; i < q_list.size(); i++)
		{
			if (q_list[i][0] == 0)
			{
				int idx = q_list[i][1];
				int value = q_list[i][2];
				int ori = b[idx];
				mp[ori]--;
				b[idx] = value;
				mp[value]++;
			}
			if (q_list[i][0] == 1)
			{
				int count = 0;
				int tar = q_list[i][1];
				for (int i = 0; i < a.size(); i++)
				{
					int find = tar - a[i];
					count += mp[find];
				}
				cout << count << endl;
				res.push_back(count);
			}
		}
		return res;
	}
};

int main() {

	solution s = solution();
	vector<int> a = { 1,2,3 };
	vector<int> b = { 1,3,4 };
	s.init(a, b);
	s.query({ {1,6},{0,0,3},{1,6} });

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








