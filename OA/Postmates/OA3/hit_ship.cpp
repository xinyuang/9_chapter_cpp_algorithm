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
	vector<vector<int>> B;
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };
public:
	void initBoard(vector<vector<int>> board)
	{
		B = board;
	}

	void attack(vector<vector<int>> hit)
	{
		for (int i = 0; i < hit.size(); i++)
		{
			int x = hit[i][0];
			int y = hit[i][1];
			if (B[x][y] == 0) cout << "Miss" << endl;
			else
			{
				if (isDead(x, y)) cout << "Dead" << endl;
				else cout << "Hit" << endl;
				B[x][y] = 0;
			}
		}
	}

	bool isDead(int x, int y)
	{
		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (!is_valid(xx, yy)) continue;
			if (B[xx][yy] == 1) return false;
		}
		return true;
	}

	bool is_valid(int x, int y)
	{
		if (x >= 0 && x < B.size() && y >= 0 && y < B[0].size()) return true;
		return false;
	}
};

int main() {

	solution s = solution();
	vector<vector<int>> board = { {1,1,1,0,0},{0,0,0,1,1},{0,0,0,0,0} };
	s.initBoard(board);
	s.attack({ {0,0},{0,1},{0,1}, {1,4},{1,3} });
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








