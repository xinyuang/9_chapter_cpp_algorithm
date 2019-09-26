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