// two sum

// using unordered_map but only the array has no duplicated number;
class Solution {
public:
	/**
	 * @param numbers: An array of Integer
	 * @param target: target = numbers[index1] + numbers[index2]
	 * @return: [index1, index2] (index1 < index2)
	 */
	vector<int> twoSum(vector<int>& numbers, int target) {
		// write your code here
		unordered_map<int, int> map;
		for (int i = 0; i < numbers.size(); i++)
		{
			if (map.find(target - numbers[i]) != map.end()) return { map[target - numbers[i]],i };
			map[numbers[i]] = i;
		}
		return {};
	}
};

// backtrack find all target combination
class Solution {
public:
	vector<vector<int>> allPairs(vector<int> array, int target) {
		// write your solution here
		vector<vector<int>> res;
		vector<int> path;
		find(res, path, array, target, 0);
		return res;
	}

	void find(vector<vector<int>>& res, vector<int>& path, vector<int>& array, int target, int start)
	{
		if (path.size() == 2 && target == 0)
		{
			res.push_back(path);
			return;
		}
		if (path.size() > 2 || target < 0) return;
		for (int i = start; i < array.size(); i++)
		{
			path.push_back(i);
			find(res, path, array, target - array[i], i + 1);
			path.pop_back();
		}
	}
};