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


//919. Meeting Rooms II
//1. sort based on start
//2. min_heap store end, if cur start > min_heap.top() then pop


class Solution {
public:
	/**
	 * @param intervals: an array of meeting time intervals
	 * @return: the minimum number of conference rooms required
	 */
	int minMeetingRooms(vector<Interval>& intervals) {
		// Write your code here
		//   [5,15] [16,23]
		//      [6,20]
		if (intervals.size() == 0) return 0;
		struct compare {
			bool operator()(Interval a, Interval b)
			{
				return a.start < b.start;
			}
		} com;
		sort(intervals.begin(), intervals.end(), com);
		priority_queue<int, vector<int>, greater<int>> min_heap;
		min_heap.push(intervals[0].end);
		for (int i = 1; i < intervals.size(); i++)
		{
			if (intervals[i].start >= min_heap.top())
			{
				min_heap.pop();
			}
			min_heap.push(intervals[i].end);

		}
		return min_heap.size();
	}
};

//1. flat interval into vector<pair<int, int>>pointsand sort
//2. sweeping line, if start, count++, if end, count--

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
	 * @param intervals: an array of meeting time intervals
	 * @return: the minimum number of conference rooms required
	 */
	int minMeetingRooms(vector<Interval>& intervals) {
		// Write your code here
		vector<pair<int, int>> counts = flatten(intervals);
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

	vector<pair<int, int>> flatten(vector<Interval>& intervals)
	{
		vector<pair<int, int>> counts;
		for (int i = 0; i < intervals.size(); i++)
		{
			counts.push_back({ intervals[i].start,1 });
			counts.push_back({ intervals[i].end,-1 });
		}
		return counts;
	}
};