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

//class base {
//public:
//	//string res() {
//	//	cout << "hi" << endl;
//	//	return "";
//	//}
//	string getName() const { return "A"; }
//};
//
//class derived : public base {
//public:
//	//virtual string res() {
//	//	cout << "hello" << endl;
//	//	return "";
//	//}
//	virtual std::string getName() const { return "B"; }
//};

//class A
//{
//public:
//	// note: no virtual keyword
//	virtual string getName() const { return "A"; }
//};
//
//class B : public A
//{
//public:
//	virtual std::string getName() const { return "B"; }
//};
//
//class C : public B
//{
//public:
//	virtual std::string getName() const { return "C"; }
//};
//
//class D : public C
//{
//public:
//	virtual std::string getName() const { return "D"; }
//};
//
//class base
//{
//public:
//	// note: no virtual keyword
//	string getName() const { return "A"; }
//};
//
//class dirived : public base
//{
//public:
//	virtual std::string getName() const { return "B"; }
//};
//
//int main(int argc, char** argv)
//{
//
//	dirived ceee;
//	base& rBaseeee{ ceee };
//
//
//	C c;
//	A& rBase{ c };
//	std::cout << rBase.getName() << '\n';
//
//	return 0;
//}

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

//class sortArr {
//public:
//	bool operator()(const pair<int, int>& a, const pair<int, int>& b)
//	{
//		if (a.first == b.first) return a.second < b.second; // if same hot return increasing id
//		return a.first < b.first;   // descending order
//	}
//} sortArr;
//vector<pair<int, int>> sort_arr;
//for (int i = 0; i < arr.size(); i++)
//{
//	sort_arr.push_back({ arr[i],load[i] });
//}
//sort(sort_arr.begin(), sort_arr.end(), sortArr);

class com {
public:
	bool operator()(const pair<int, int>& a, const pair<int, int>& b)
	{
		if (a.second == b.second) return a.first > b.first;
		return a.second > b.second;
	}
};

class comp {
public:
	bool operator()(const pair<int, int>& a, const pair<int, int>& b)
	{
		if (a.second == b.second) return a.first < b.first; // if same hot return increasing id
		return a.second > b.second; // descending order
	}
} compare;

vector<int> findHotServer(int k, vector<int>& arr, vector<int>& load)
{
	if (arr.size() != load.size()) return {};
	map<int, int> hot;
	priority_queue<pair<int, int>, vector<pair<int, int>>, com> min_heap;  // pair<int,int> idx, endtime


	for (int i = 0; i < arr.size(); i++)
	{
		//cout << sort_arr[i].first << " - " << sort_arr[i].second << endl;
		int start = arr[i];
		int end = arr[i] + load[i] - 1;
		if (min_heap.empty())
		{
			min_heap.push({ 1,end });
			hot[1]++;
		}
		else
		{
			pair<int, int> cur = min_heap.top();
			if (cur.second <= start)
			{
				min_heap.pop();
				min_heap.push({ cur.first,end });
				hot[cur.first]++;
			}
			else
			{
				if (min_heap.size() < k)
				{
					min_heap.push({ min_heap.size()+1,end });
					hot[min_heap.size()]++;
					cout << "?" << min_heap.size() + 1 << " "  << k << endl;
				}
				// else drop request
			}
		}
	}
	if (hot.empty()) return {};
	vector<pair<int, int>> hot_id;
	for (auto item : hot)
	{
		hot_id.push_back({ item.first,item.second });
	}
	sort(hot_id.begin(), hot_id.end(), compare);  // hot decreasing order
	vector<int> id_list;
	int count = hot_id[0].second;

	for (int i = 0; i < hot_id.size(); i++)
	{
		if (hot_id[i].second != count) break;
		id_list.push_back(hot_id[i].first);
		//cout << hot_id[i].first << " " << hot_id[i].second << endl;
	}
	return id_list;
}

int main() {
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
	int k = 3;
	vector<int> arr = { 1,2,3,4,5 };
	vector<int> load = { 6,3,4,4,4 };
	vector<int> ids = findHotServer(k, arr, load);
	for (int i = 0; i < ids.size(); i++)
	{
		cout << ids[i] << endl;
	}
	vector<int> exp = { 2 };
	assert(ids == exp);
	cout << " test1 passed " << endl;

	vector<int> arr1 = { 1,2,3,5,6,8,10};
	vector<int> load1 = { 4,4,4,5,4,5,5 };
	vector<int> ids1 = findHotServer(k, arr1, load1);
	for (int i = 0; i < ids1.size(); i++)
	{
		cout << ids1[i] << endl;
	}
	vector<int> exp1 = { 1 };
	assert(ids1 == exp1);
	cout << " test2 passed " << endl;

	vector<int> arr2 = { 1,3,5 };
	vector<int> load2 = { 1,1,1 };
	vector<int> ids2 = findHotServer(k, arr2, load2);
	for (int i = 0; i < ids2.size(); i++)
	{
		cout << ids2[i] << endl;
	}
	vector<int> exp2 = {  1 };
	assert(ids2 == exp2);
	cout << " test3 passed " << endl;

	vector<int> arr3= { 1,2,3,4,6,6 };
	vector<int> load3 = { 10,1,2,1,1,1 };
	vector<int> ids3 = findHotServer(k, arr3, load3);
	for (int i = 0; i < ids3.size(); i++)
	{
		cout << ids3[i] << endl;
	}
	vector<int> exp3 = { 2 };
	assert(ids3 == exp3);
	cout << " test4 passed " << endl;

	vector<int> arr4 = {  1,4,5,5,6,6,7,8,10 };
	vector<int> load4 = { 2,4,3,2,1,1,8,4,6 };
	vector<int> ids4 = findHotServer(4, arr4, load4);
	for (int i = 0; i < ids4.size(); i++)
	{
		cout << ids4[i] << endl;
	}
	vector<int> exp4 = { 3 };
	assert(ids4 == exp4);
	cout << " test4 passed " << endl;
	return 0;
}








