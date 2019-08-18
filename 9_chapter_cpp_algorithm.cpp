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

int main()
{
	// a,b,d,f
	map<char, int> m;
	m['a'] = 1;
	m['b'] = 2;
	m['d'] = 4;
	m['f'] = 5;
	cout << m.lower_bound('c')->first << endl;
	cout << m.upper_bound('c')->first << endl;
	return 0;
}

