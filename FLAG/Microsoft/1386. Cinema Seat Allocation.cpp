//1386. Cinema Seat Allocation
// 3 case, left, mid, right
//           v    v     v     2
//           v    v     x     1
//           v    x     v     -
//           x    v     v     1
//           x    x     v     1
//           x    v     x     -
//           v    x     x     1
//           x    x     x     0

class Solution {
public:
	int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
		// 0,1,2   3,4,5,6  7,8,9
		//   1,2   3,4
		//         3,4,5,6  
		//             5,6  7,8
		//   left    mid      right    3
		//    F       T         F
		unordered_map<int, vector<bool>> mp; // line, col
		for (int i = 0; i < reservedSeats.size(); i++)
		{
			int line = reservedSeats[i][0];
			if (!mp.count(line)) mp[line] = { true,true,true };
			int col = reservedSeats[i][1];
			if (col >= 2 && col <= 5) mp[line][0] = false;
			if (col >= 4 && col <= 7) mp[line][1] = false;
			if (col >= 6 && col <= 9) mp[line][2] = false;
		}
		int res = 2 * n;
		for (auto ele : mp)
		{
			vector<bool> col = ele.second;
			if (col[0] && col[1] && col[2]) res -= 0;
			else if (!col[0] && !col[1] && !col[2]) res -= 2;
			else res -= 1;
		}
		return res;
	}
};