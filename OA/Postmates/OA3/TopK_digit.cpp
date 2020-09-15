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
	vector<int> mostFreq(vector<int> s)
	{
		vector<int> res;
		unordered_map<int, int> mp;
		for (int i = 0; i < s.size(); i++)
		{
			string ss = to_string(s[i]);
			for (int j = 0; j < ss.size(); j++)
			{
				mp[ss[j] - '0']++;
			}
		}
		typedef pair<int, int> pos;
		class com {
		public:
			bool operator()(const pos a, const pos b) const
			{
				if (a.second == b.second) return a.first < b.first;
				return a.second > b.second;
			}
		};
		priority_queue<pos, vector<pos>, com> min_heap;
		for (auto it : mp)
		{
			min_heap.push(it);
			if (min_heap.size() > 3) min_heap.pop();
		}
		while (!min_heap.empty())
		{
			res.push_back(min_heap.top().first);
			min_heap.pop();
		}
		reverse(res.begin(), res.end());
		for(int i = 0; i < res.size(); i++) cout << res[i] << " ";
		cout << endl;
		return res;
	}
};

int main() {

	solution s = solution();
	s.mostFreq({ 12555,1,3 });

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








