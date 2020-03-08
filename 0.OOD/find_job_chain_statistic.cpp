// give a graph of job, start -> end, end job_id = 0
// return each job chain info
// 9->1->2->0
//    3->4->0

//#job_id, runtime_in_seconds, next_job_id
//1, 60, 2
//2, 62, 0
//3, 5, 4
//4, 50, 0
//9, 60, 1
//end


#include <cctype>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <utility>

class LinkedNode {
public:
	int work_time;
	int job_id;
	LinkedNode* next;
	LinkedNode(int id, int cur_time) :job_id(id), work_time(cur_time), next(nullptr) {}
};

using namespace std;

string padding(string str, int len)
{
	if (len > str.size())
	{
		string pad = "";
		for (int i = 0; i < (len - str.size()); i++)
		{
			pad.push_back('0');
		}
		string pad_str = pad + str;
		return pad_str;
	}
	return str;
}

string get_time_format(int ttl_seconds) {
	string hour = padding(to_string(ttl_seconds / 3600), 2);
	string minute = padding(to_string((ttl_seconds % 3600) / 60), 2);
	string second = padding(to_string(ttl_seconds % 60), 2);
	string res = hour + ":" + minute + ":" + second;
	return res;
}

vector<int> parseLine(string line, bool& good_format) {
	vector<int> res;
	string cur = "";
	for (int i = 0; i < line.size(); i++)
	{
		if (line[i] == ',') {
			int cur_value = stoi(cur);
			res.push_back(cur_value);
			cur = "";
		}
		else {
			if (!isdigit(line[i])) {
				good_format = false;
				return {};
			}
			cur.push_back(line[i]);
		}
	}
	int cur_value = stoi(cur);
	res.push_back(cur_value);
	if (res.size() != 3) good_format = false;
	return res;
}

vector<string> dfs(LinkedNode* curNode) {
	vector<string> res;
	int ttl_time = 0;
	int start_job = curNode->job_id;
	int end_job = -1;
	int count = 0;
	while (curNode->next && curNode->next->job_id != 0)
	{
		ttl_time += curNode->work_time;
		count++;
		curNode = curNode->next;
	}
	ttl_time += curNode->work_time;
	count++;
	end_job = curNode->job_id;
	int avg = ttl_time / count;
	string ttl_runtime = get_time_format(ttl_time);
	string avg_runtime = get_time_format(avg);
	res.push_back(to_string(start_job));
	res.push_back(to_string(end_job));
	res.push_back(to_string(count));
	res.push_back(ttl_runtime);
	res.push_back(avg_runtime);
	return res;
}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */

	LinkedNode* dummy = new LinkedNode(2, 2);
	LinkedNode* cur = dummy;

	bool good_format = true;
	pair<int, int> a = { 0,1 };
	string header = "";
	cin >> header;
	if (header != "#job_id,runtime_in_seconds,next_job_id")
	{
		cout << "Malformed Input" << endl;
		return 0;
	}
	// cout << header << endl;
	string cur_line = "start";
	unordered_map<int, LinkedNode*> mp;
	unordered_map<int, int> indegree;
	unordered_map<int, int> edge;
	while (cur_line != "end")
	{
		cur_line = "";
		cin >> cur_line;
		if (cur_line == "end") break;
		vector<int> content = parseLine(cur_line, good_format);
		if (!good_format)
		{
			cout << "Malformed Input" << endl;
			return 0;
		}
		int cur_id = content[0];
		int cur_time = content[1];
		int next_id = content[2];
		LinkedNode* new_node = new LinkedNode(content[0], content[1]);
		mp[cur_id] = new_node;
		if (!indegree.count(cur_id)) indegree[cur_id] = 0;
		indegree[next_id]++;
		edge[cur_id] = next_id;
	}
	for (auto cur_l : edge)
	{
		int s = cur_l.first;
		int e = cur_l.second;
		mp[s]->next = mp[e];
	}
	for (auto cur_node : indegree)
	{
		if (indegree[cur_node.first] == 0)
		{
			vector<string> res = dfs(mp[cur_node.first]);
			cout << "start_job: " << res[0] << endl;
			cout << "last_job: " << res[1] << endl;
			cout << "number_of_jobs: " << res[2] << endl;
			cout << "job_chain_runtime: " << res[3] << endl;
			cout << "average_job_time: " << res[4] << endl;
			cout << "-" << endl;
		}
	}
	return 0;
}