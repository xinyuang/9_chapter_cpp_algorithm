//// 9_chapter_cpp_algorithm.cpp : Defines the entry point for the application.
////
//
//#include "9_chapter_cpp_algorithm.h"
//#include <iostream>
//#include <time.h> 
//#include <ppl.h>
//#include <iomanip>
//#include <vector>
//#include <string>
//#include <unordered_map>
//#include <unordered_set>
//#include <map>
//
//using namespace std;
//
//template<class tA, class tB>
//int addNums(tA num_a, tB num_b)
//{
//	std::unordered_map<tA, int> mp;
//	mp[num_a] = 1;
//	return mp[num_a];
//}
//
//class Solution {
//public:
//	bool containsPermutation(string s1, string s2) {
//		// write your solution here
//		if (s1.size() > s2.size()) return false;
//		vector<int> pattern(26, 0);
//		for (int i = 0; i < s1.size(); i++)
//		{
//			pattern[s1[i] - 'a']++;
//		}
//		vector<int> window(26, 0);
//		for (int i = 0; i < s1.size(); i++)
//		{
//			window[s2[i] - 'a']++;
//		}
//		int win_size = s1.size();
//		for (int i = s1.size(); i < s2.size(); i++)
//		{
//			if (window == pattern) return true;
//			cout << i << " " << win_size << endl;
//			window[s2[i - win_size] - 'a']--;
//			window[s2[i] - 'a']++;
//		}
//		return false;
//	}
//};
//
//
//int main(int argc, char** argv)
//{
//	// a,b,d,f
//	string a = "123";
//	a.append(2, '.');
//	cout << a << endl;
//	double dA = 2.0;
//	int iB = 1;
//	addNums(dA, iB);
//
//	string s1 = "ab";
//	string s2 = "eidbaooo";
//	Solution find = Solution();
//	bool res = find.containsPermutation(s1,s2);
//	cout << res << endl;
//
//	return 0;
//}
//
//
//




