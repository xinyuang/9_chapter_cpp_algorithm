// 9_chapter_cpp_algorithm.cpp : Defines the entry point for the application.
//

#include "9_chapter_cpp_algorithm.h"
#include <iostream>
#include <time.h> 
// #include <ppl.h>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
	// int a = 4;
	// int b = 3;
	vector<int> myArr = {3,4,5,7};
	// auto it = lower_bound(myArr.begin(), myArr.end(),1);
	// cout << "??" << *it << endl;
	// cout << "!!" << *(--it) << endl;
	// cout << a/b << endl;

	// string str = "abcd";
	// cout << str.size() << endl;

	// ostringstream oss;
	// oss << "ab" << " " << "cd" << " " << "ef";
	// cout << oss.str() << endl;
	istringstream iss("12, ah 23 45 end");
	// cout << iss.str() << endl;
	string line;

	while(iss >> line)
	{
		cout << line << "??? " << endl;
	}
	
	// begin:
	// int i = 0;
	
	// 	while(line != "end")
	// 	{
	// 		try{
	// 			iss >> line;
	// 			cout << "?" << line << endl;
	// 			cout << " to digit " << stoi(line) << endl;
	// 			cout << myArr[i++] << endl;
	// 			if(i > 3) goto begin;
	// 		}
	// 		catch(runtime_error err)
	// 		{
	// 			cout << "???" << err.what() << endl;
	// 		}
	// 		// catch(exception err)
	// 		// {
	// 		// 	cout << "000" << err.what() << endl;
	// 		// }
	// 	}

	// cout << "end!" << endl;

	// vector<int> vec;
	// int ptr = 2;
	// bool res = (vec[ptr++] <= vec[ptr]);
	// cout << res << endl;
	// auto beg = vec.begin();
	// while(beg != vec.end())
	// {
	// 	*beg = *beg++;
	// 	cout << *beg << endl;
	// }
	// long long a = 0;
	// char b = 'a';
	// cout << (sizeof(b)) << endl;
	
	return 0;
}