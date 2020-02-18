//805. Maximum Association Set
//1. union find add associate books unordered_map<string, string> father
//2. for loop cluster books use unordered_map<string, unordered_set<string>> cluster
//3. find the cluster with maximum sub_set size, return list(sub_set)

class Solution {
private:
	unordered_map<string, string> father;
public:
	/**
	 * @param ListA: The relation between ListB's books
	 * @param ListB: The relation between ListA's books
	 * @return: The answer
	 */
	vector<string> maximumAssociationSet(vector<string>& ListA, vector<string>& ListB) {
		// Write your code here
		if (ListA.size() == 0 || ListB.size() == 0 || ListA.size() != ListB.size()) return {};
		for (int i = 0; i < ListA.size(); i++)
		{
			if (!father.count(ListA[i])) father[ListA[i]] = ListA[i];
			if (!father.count(ListB[i])) father[ListB[i]] = ListB[i];
			addEdge(ListA[i], ListB[i]);
		}
		unordered_map<string, set<string>> mp;
		for (int i = 0; i < ListA.size(); i++)
		{
			string cur_rootA = findRoot(ListA[i]);
			mp[cur_rootA].insert(ListA[i]);
			string cur_rootB = findRoot(ListB[i]);
			mp[cur_rootB].insert(ListB[i]);
		}
		int max_size = 0;
		string max_id = "";
		for (auto ele : mp)
		{
			if (ele.second.size() > max_size)
			{
				max_size = ele.second.size();
				max_id = ele.first;
			}
		}
		vector<string> res;
		for (string book : mp[max_id])
		{
			res.push_back(book);
		}
		return res;
	}

	void addEdge(string a, string b)
	{
		string root_a = findRoot(a);
		string root_b = findRoot(b);
		if (root_b != root_a)
		{
			father[root_a] = root_b;
		}
	}

	string findRoot(string x)
	{
		while (father[x] != x)
		{
			x = father[x];
		}
		return x;
	}


};