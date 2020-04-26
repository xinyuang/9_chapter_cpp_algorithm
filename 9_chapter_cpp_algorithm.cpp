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

using namespace std;

  //     33,4,2
  //        _
	 //  __| |	
  //    |    |_
	 // |      |   
	 //  12 3 4   

	 //3-> 4
	 //1-> 3
	 //2-> 1
	 //4-> 2

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

class Solution {
public:
	int minNumberOfFrogs(string croakOfFrogs) {
		string str = croakOfFrogs;
		vector<int> visited(croakOfFrogs.size(), 0);
		vector<vector<int>> interval;
		for (int i = 0; i < str.size(); i++)
		{
			if (visited[i]) continue;
			bool isReal = true;
			if (str[i] == 'c') isReal = search_valid(i, str, visited, interval);
			if (!isReal) return -1;
		}

		 for(int i = 0; i < interval.size(); i++)
		 {
		     cout << interval[i][0] << " " << interval[i][1] << endl;
		 }
		 cout << interval.size() << endl;
		vector<vector<int>> flatten;
		for (int i = 0; i < interval.size(); i++)
		{
			flatten.push_back({ interval[i][0],1 });
			flatten.push_back({ interval[i][1],-1 });
		}
		class compare {
		public:
			bool operator()(const vector<int>& a, const vector<int>& b)
			{
				if (a[0] == b[0]) return a[1] < b[1];
				return a[0] < b[0];
			}
		} com;
		sort(flatten.begin(), flatten.end(), com);
		int min_count = -1;
		int count = 0;
		for (int i = 0; i < flatten.size(); i++)
		{
			if (flatten[i][1] == 1) count++;
			else count--;
			min_count = max(min_count, count);
		}
		return min_count;
	}

	bool search_valid(int start, string& str, vector<int>& visited, vector<vector<int>>& interval)
	{
		string valid = "croak";
		int cur = start;
		int ptr = 0;
		while (cur < str.size())
		{
			while (cur < str.size() && str[cur] != valid[ptr]) cur++;
			ptr++; cur++;
			if (ptr == valid.size())
			{
				interval.push_back({ start,--cur });
				return true;
			}
		}
		return false;
	}
};

int main(int argc, char** argv)
{
	// a,b,d,f
	string a = "ccccccccccrrccccccrcccccccccccrcccccccccrcccccccccccrcccccrcccrrcccccccccccccrocrrcccccccccrccrocccccrccccrrcccccccrrrcrrcrccrcoccroccrccccccccorocrocccrrrrcrccrcrcrcrccrcroccccrccccroorcacrkcccrrroacccrrrraocccrrcrrccorooccrocacckcrcrrrrrrkrrccrcoacrcorcrooccacorcrccccoocroacroraoaarcoorrcrcccccocrrcoccarrorccccrcraoocrrrcoaoroccooccororrrccrcrocrrcorooocorarccoccocrrrocaccrooaaarrcrarooaarrarrororrcrcckracaccorarorocacrrarorrraoacrcokcarcoccoorcrrkaocorcrcrcrooorrcrroorkkaaarkraroraraarooccrkcrcraocooaoocraoorrrccoaraocoorrcokrararrkaakaooroorcororcaorckrrooooakcarokokcoarcccroaakkrrororacrkraooacrkaraoacaraorrorrakaokrokraccaockrookrokoororoooorroaoaokccraoraraokakrookkroakkaookkooraaocakrkokoraoarrakakkakaroaaocakkarkoocokokkrcorkkoorrkraoorkokkarkakokkkracocoaaaaakaraaooraokarrakkorokkoakokakakkcracarcaoaaoaoorcaakkraooaoakkrrroaoaoaarkkarkarkrooaookkroaaarkooakarakkooaokkoorkroaaaokoarkorraoraorcokokaakkaakrkaaokaaaroarkokokkokkkoakaaookkcakkrakooaooroaaaaooaooorkakrkkakkkkaokkooaakorkaroaorkkokaakaaaaaocrrkakrooaaroroakrakrkrakaoaaakokkaaoakrkkoakocaookkakooorkakoaaaaakkokakkorakaaaaoaarkokorkakokakckckookkraooaakokrrakkrkookkaaoakaaaokkaokkaaoakarkakaakkakorkaakkakkkakaaoaakkkaoaokkkakkkoaroookakaokaakkkkkkakoaooakcokkkrrokkkkaoakckakokkocaokaakakaaakakaakakkkkrakoaokkaakkkkkokkkkkkkkrkakkokkroaakkakaoakkoakkkkkkakakakkkaakkkkakkkrkoak";
	cout << a.size() << endl;
	//a.append(2, '.');
	//cout << a << endl;
	//double dA = 2.0;
	//int iB = 1;
	//addNums(dA, iB);

	//string s1 = "ab";
	//string s2 = "eidbaooo";
	Solution find = Solution();
	bool res = find.minNumberOfFrogs(a);
	cout << res << endl;

	return 0;
}









