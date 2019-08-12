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

using namespace std;

int main()
{
	string test = "24354364fghdgsgq23rq&q3rlkgj*lkgjs%akwhf;kheg;ef";
	hash<string> t;
	unordered_map<string, int> map;
	unordered_set<string> set;
	cout << to_string(t(test)) << endl;
	cout << test << endl;
	return 0;
}

