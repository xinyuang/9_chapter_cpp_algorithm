//1423. Maximum Points You Can Obtain from Cards
//think reversely, get the minimum sum of sliding window, then return sum - min_mid

class Solution {
public:
	int maxScore(vector<int>& cardPoints, int k) {
		int w_size = cardPoints.size() - k;
		int cur_sum = 0;
		int sum = 0;
		for (int i = 0; i < w_size; i++)
		{
			cur_sum += cardPoints[i];
			sum += cardPoints[i];
		}
		int min_v = cur_sum;
		for (int i = w_size; i < cardPoints.size(); i++)
		{
			sum += cardPoints[i];
			cur_sum += (cardPoints[i] - cardPoints[i - w_size]);
			min_v = min(min_v, cur_sum);
		}
		return sum - min_v;
	}
};