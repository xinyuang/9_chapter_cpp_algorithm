//1373. Movies on Flight
//1. brute force n2
//1. sort with idx, two pointer

class Solution {
public:
	/**
	 * @param arr: An integer array
	 * @param k: An integer
	 * @return: return the pair of movies index with the longest total duration
	 */
	vector<int> FlightDetails(vector<int>& arr, int k) {
		// write your code here
		vector<int> res = { -1,-1 };
		int min_diff = INT_MAX;
		for (int i = 0; i < arr.size(); i++)
		{
			for (int j = i + 1; j < arr.size(); j++)
			{
				if (k - 30 - arr[i] - arr[j] >= 0)
				{
					if (min_diff >= k - 30 - arr[i] - arr[j])
					{
						if (min_diff == k - 30 - arr[i] - arr[j])
						{
							int longest = max(arr[i], arr[j]);
							int orilong = max(arr[res[0]], arr[res[1]]);
							if (longest <= orilong) continue;
						}
						res[0] = i;
						res[1] = j;
						min_diff = k - 30 - arr[i] - arr[j];
					}
				}
			}
		}
		return res;
	}
};

class Solution {
public:
	/**
	 * @param arr: An integer array
	 * @param k: An integer
	 * @return: return the pair of movies index with the longest total duration
	 */
	vector<int> FlightDetails(vector<int>& arr, int k) {
		// write your code here
		vector<pair<int, int>> movies;
		for (int i = 0; i < arr.size(); i++)
		{
			movies.push_back({ arr[i],i });
		}
		class cmp {
		public:
			bool operator()(const pair<int, int>& a, const pair<int, int>& b)
			{
				if (a.first == b.first) return a.second < b.second;
				return a.first < b.first;
			}
		} com;
		sort(movies.begin(), movies.end(), com);
		int left = 0, right = arr.size() - 1;
		int min_diff = INT_MAX;
		int res_long = 0;
		vector<int> res = { -1,-1 };
		for (int left = 0; left < movies.size(); left++)
		{
			while (left < right && movies[left].first + movies[right].first + 30 > k) right--;
			int cur_diff = k - movies[left].first - movies[right].first - 30;
			if (left < right && abs(cur_diff) <= min_diff)
			{
				int longest = max(movies[left].first, movies[right].first);
				if (cur_diff == min_diff && res_long >= longest) continue;
				min_diff = cur_diff;
				res[0] = min(movies[right].second, movies[left].second);
				res[1] = max(movies[right].second, movies[left].second);
				res_long = longest;
			}
		}
		return res;
	}
};