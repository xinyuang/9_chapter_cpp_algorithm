//1579. Alphabetic string calculation
//1. use unordered_map store freq, set store freq times, queue store duplicate times
//2. while loop till find the empty times, count += (cur - times[next]) then times[next]++

class Solution {
public:
	/**
	 * @param aString: letter string
	 * @return: the Minimum times
	 */
	int Kstart(string& aString) {
		// write your code here
		unordered_map<char, int> frq;
		for (int i = 0; i < aString.size(); i++)
		{
			frq[aString[i]]++;
		}
		unordered_map<int, int> times;
		queue<int> q;
		for (auto e : frq)
		{
			times[e.second]++;
		}
		for (auto t : times)
		{
			if (t.second > 1)
			{
				for (int i = 2; i <= t.second; i++)
				{
					q.push(t.first);
				}
			}
		}
		int count = 0;
		while (!q.empty())
		{
			int cur = q.front(); q.pop();
			int next_empty = cur;
			while (times.count(next_empty)) next_empty--;
			count += (cur - next_empty);
			if (next_empty > 0)
			{
				times[next_empty]++;
			}
		}
		return count;
	}
};