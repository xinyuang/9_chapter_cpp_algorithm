// 156. Merge Intervals
// sort interval by start, push_back new interval or update max(res.back().end, new interval.end)

/**
 * Definition of Interval:
 * class Interval {
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
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
        vector<Interval> res;
        class compare{
        public:
            bool operator()(const Interval& a, const Interval& b)
            {
                if(a.start == b.start) return a.end < b.end;
                return a.start < b.start;
            }
        } com;
        sort(intervals.begin(),intervals.end(),com);
        for(int i = 0; i < intervals.size(); i++)
        {
            if(i == 0 || res.back().end < intervals[i].start) res.push_back(intervals[i]);
            else res.back().end = max(intervals[i].end,res.back().end);
        }
        return res;
    }
};