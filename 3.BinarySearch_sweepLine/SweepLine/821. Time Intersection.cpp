//821. Time Intersection
//1. flat point paired with in and out flag
//2. if (count == 2) both login


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
		/**
		 * @param seqA: the list of intervals
		 * @param seqB: the list of intervals
		 * @return: the time periods
		 */
		vector<Interval> timeIntersection(vector<Interval>& seqA, vector<Interval>& seqB) {
			// Write your code here
			vector<pair<int, int>> points;
			flatten(seqA, points);
			flatten(seqB, points);
			class compare {
			public:
				bool operator()(const pair<int, int>& a, const pair<int, int>& b)
				{
					if (a.first == b.first) return a.second < b.second;
					return a.first < b.first;
				}
			} com;
			sort(points.begin(), points.end(), com);
			int count = 0;
			int last_count = 0;
			int login = 0, logout = 0;
			vector<Interval> res;
			for (int i = 0; i < points.size(); i++)
			{
				if (points[i].second == 1) count++;
				else count--;
				if (count == 2 && last_count == 1) login = points[i].first;
				if (count == 1 && last_count == 2) {
					logout = points[i].first;
					res.push_back(Interval(login, logout));
				}
				last_count = count;
			}
			return res;
		}

		void flatten(vector<Interval>& seq, vector<pair<int, int>>& points)
		{

			for (int i = 0; i < seq.size(); i++)
			{
				points.push_back({ seq[i].start,1 });
				points.push_back({ seq[i].end,-1 });
			}
		}
};