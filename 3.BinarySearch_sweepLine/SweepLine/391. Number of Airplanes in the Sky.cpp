//391. Number of Airplanes in the Sky
//1. flat sort pair<int, int> idx, flag
//2. sweep line in count++ out count--

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */



	class Solution {
	public:

		class compare {
		public:
			bool operator()(const pair<int, int>& a, const pair<int, int>& b)
			{
				if (a.first == b.first) return a.second < b.second;
				return a.first < b.first;
			}
		} com;
		/**
		 * @param airplanes: An interval array
		 * @return: Count of airplanes are in the sky.
		 */
		int countOfAirplanes(vector<Interval>& airplanes) {
			// write your code here
			vector<pair<int, int>> counts = flatten(airplanes);
			sort(counts.begin(), counts.end(), com);
			int cur_count = 0;
			int res = 0;
			for (int i = 0; i < counts.size(); i++)
			{
				if (counts[i].second > 0) cur_count++;
				else cur_count--;
				res = max(res, cur_count);
			}
			return res;
		}

		vector<pair<int, int>> flatten(vector<Interval>& airplanes)
		{
			vector<pair<int, int>> res;
			for (int i = 0; i < airplanes.size(); i++)
			{
				res.push_back({ airplanes[i].start,1 });
				res.push_back({ airplanes[i].end,-1 });
			}
			return res;
		}
};