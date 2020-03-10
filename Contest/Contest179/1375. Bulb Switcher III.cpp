//1375. Bulb Switcher III
//There is a room with n bulbs, numbered from 1 to n, arranged in a row from left to right.Initially, all the bulbs are turned off.
//
//At moment k(for k from 0 to n - 1), we turn on the light[k] bulb.A bulb change color to blue only if it is onand all the previous bulbs(to the left) are turned on too.
//
//Return the number of moments in which all turned on bulbs are blue.

//xxvxx  vvvxx  vvxvx
//  no     yes   no

// if the max_id is equal to the number of on light, all blue

class Solution {
public:
	int numTimesAllBlue(vector<int>& light) {
		int max_id = 0;
		int moment = 0;
		for (int i = 0; i < light.size(); i++)
		{
			if (light[i] > max_id) max_id = light[i];
			if (max_id == i + 1) moment++;
		}
		return moment;
	}
};