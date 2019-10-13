// 9_chapter_cpp_algorithm.cpp : Defines the entry point for the application.
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

using namespace std;

template<class tA, class tB>
int addNums(tA num_a, tB num_b)
{
	std::unordered_map<tA, int> mp;
	mp[num_a] = 1;
	return mp[num_a];
}


int main()
{
	// a,b,d,f
	string a = "123";
	a.append(2, '.');
	cout << a << endl;
	double dA = 2.0;
	int iB = 1;
	addNums(dA, iB);
	return 0;
}

