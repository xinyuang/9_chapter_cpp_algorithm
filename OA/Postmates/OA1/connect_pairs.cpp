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

class graph{
private:
	unordered_map<int,vector<int>> mp;
	map<int,int> freq;
public:
	graph(vector<vector<int>> pairs)
	{
		for(int i = 0; i < pairs.size(); i++)
		{
			mp[pairs[i][0]].push_back(pairs[i][1]);
			mp[pairs[i][1]].push_back(pairs[i][0]);
			freq[pairs[i][0]]++;
			freq[pairs[i][1]]++;
		}
	}

	void print()
	{
		auto it = mp.begin();
		queue<int> q;
		unordered_set<int> visited;
		q.push(it->first);
		visited.insert(it->first);
		while(!q.empty())
		{
			int cur = q.front(); q.pop();
			cout << cur << " ";
			vector<int> next = mp[cur];
			for(int i = 0; i < next.size(); i++)
			{
				if(visited.count(next[i])) continue;
				q.push(next[i]);
				visited.insert(next[i]);
			}
		}
		cout << endl;
	}
};

int main() {
	vector<vector<int>> node_pairs = {{1,4}, {5,3}, {4,3}};
	graph a = graph(node_pairs);
	a.print();

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








