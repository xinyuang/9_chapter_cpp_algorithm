//1409. Queries on a Permutation With Key
//move queried to the first


class Solution {
public:
	vector<int> processQueries(vector<int>& queries, int m) {
		vector<int> array(m, 0);
		for (int i = 1; i <= m; i++) array[i - 1] = i;
		vector<int> res;
		for (int i = 0; i < queries.size(); i++)
		{
			int tar = queries[i];
			int sub_idx = find(tar, array);
			res.push_back(sub_idx);
		}
		return res;
	}

	int find(int tar, vector<int>& array)
	{
		int idx = 0;
		for (int i = 0; i < array.size(); i++)
		{
			if (array[i] == tar)
			{
				idx = i;
				break;
			}
		}
		int store = array[idx];
		for (int i = idx; i >= 1; i--)
		{
			array[i] = array[i - 1];
		}
		array[0] = store;
		return idx;
	}
};