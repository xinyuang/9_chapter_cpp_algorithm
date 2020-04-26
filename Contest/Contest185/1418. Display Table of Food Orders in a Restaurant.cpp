//1418. Display Table of Food Orders in a Restaurant
//map of id - orders(item, times)

class Solution {
public:
	vector<vector<string>> displayTable(vector<vector<string>>& orders) {
		map<int, unordered_map<string, int>> mp;  // table id { fItem : number }
		set<string> menu;
		for (int i = 0; i < orders.size(); i++)
		{
			if (orders[i].size() < 3) continue;
			menu.insert(orders[i][2]);
			int table_id = stoi(orders[i][1]);
			if (!mp.count(table_id)) mp[table_id] = {};
			mp[table_id][orders[i][2]]++;
		}
		vector<vector<string>> res;
		vector<string> header = { "Table" };
		for (auto item : menu)
		{
			header.push_back(item);
		}
		res.push_back(header);
		for (auto ele : mp)
		{
			int tableID = ele.first;
			vector<string> line = { to_string(tableID) };
			for (auto item : menu)
			{
				if (!mp[tableID].count(item)) line.push_back("0");
				else line.push_back(to_string(mp[tableID][item]));
			}
			res.push_back(line);
		}
		return res;
	}
};
