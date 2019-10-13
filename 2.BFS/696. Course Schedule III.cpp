// Course Schedule III
// sort with deadline , max_heap push course, if ttl time > deadline, pop the longest one
class Solution {
public:
	/**
	 * @param courses: duration and close day of each course
	 * @return: the maximal number of courses that can be taken
	 */
	int scheduleCourse(vector<vector<int>>& courses) {
		// write your code here
		struct compare {
			bool operator()(vector<int> a, vector<int> b)
			{
				return a[1] < b[1];
			}
		} com;
		sort(courses.begin(), courses.end(), com);

		priority_queue<int, vector<int>> q;
		int ttl_time = 0;
		for (int i = 0; i < courses.size(); i++)
		{
			int deadline = courses[i][1];
			if (ttl_time + courses[i][0] <= deadline)
			{
				q.push(courses[i][0]);
				ttl_time += courses[i][0];
			}
			else
			{
				if (!q.empty() && q.top() > courses[i][0])
				{
					ttl_time = ttl_time - q.top() + courses[i][0];
					q.pop();
					q.push(courses[i][0]);
				}
			}
		}
		return q.size();
	}
};