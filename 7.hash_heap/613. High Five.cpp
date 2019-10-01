/**
 * Definition for a Record
 * class Record {
 * public:
 *   int id, score;
 *   Record(int id, int score) {
 *     this->id = id;
 *     this->score = score;
 *   }
 * };
 */

//  High Five
class Solution {
public:
	/**
	 * @param results a list of <student_id, score>
	 * @return find the average of 5 highest scores for each person
	 * map<int, double> (student_id, average_score)
	 */
	map<int, double> highFive(vector<Record>& results) {
		// Write your code here
		struct compare {
			bool operator()(int a, int b)
			{
				return b < a;
			}
		};
		unordered_map<int, priority_queue<int, vector<int>, compare>> mp;
		for (int i = 0; i < results.size(); i++)
		{
			int id = results[i].id;
			int score = results[i].score;
			if (mp[id].size() < 5) mp[id].push(score);
			else
			{
				if (score > mp[id].top())
				{
					mp[id].push(score);
					mp[id].pop();
				}
			}
		}
		map<int, double> res;
		for (auto stu : mp)
		{
			double sum = 0;
			auto scores = stu.second;
			double ttl = scores.size();
			while (!scores.empty())
			{
				sum += scores.top();
				scores.pop();
			}
			res[stu.first] = (sum / ttl);
		}
		return res;
	}

};