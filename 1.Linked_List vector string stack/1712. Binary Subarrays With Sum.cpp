// Binary Subarrays with sum

// presum array
// unordered_map<presum,idx>
class Solution {
public:
	/**
	 * @param A: an array
	 * @param S: the sum
	 * @return: the number of non-empty subarrays
	 */
	int numSubarraysWithSum(vector<int>& A, int S) {
		// Write your code here.
		int res = 0;
		//    1,0,0,0,1,0,1      3*4/2 + 1*2/2
		if (S == 0)
		{
			int count = 0;
			for (int i = 0; i <= A.size(); i++)
			{
				if (i != A.size() && A[i] == 0) count++;
				else
				{
					res += count * (count + 1) * 0.5;
					count = 0;
				}
			}
			return res;
		}
		//                1,0,0,0,1,0,0,1,0,*   S = 2
		// presum       0,1,1,1,1,2,2,2,3,3,3  
		// idx         -1,0,      4,    7   8     [3,0]  (0 - (-1)) * (7 - 4)  + (4 - 0) * (8-7)
		//              p l       r     i
		unordered_map<int, int> mp;  //presum, idx
		mp[0] = -1;
		int presum = 0;
		for (int i = 0; i <= A.size(); i++)
		{
			if (i != A.size()) presum += A[i];
			if (i == A.size()) presum++;
			if (mp.count(presum))continue;
			mp[presum] = i;
			if (presum <= S) continue;
			int prev_idx = mp[presum - S - 1];
			int left_idx = mp[presum - S];
			int right_idx = mp[presum - 1];
			res += (i - right_idx) * (left_idx - prev_idx);
		}
		return res;
	}
};

// use deque idx
//                1,0,0,0,1,0,0,1,0,*   S = 2
// presum       0,1,1,1,1,2,2,2,3,3,3  
// idx         -1,0,      4,    7   8     [3,0]  (0 - (-1)) * (7 - 4)  + (4 - 0) * (8-7)
//              p l       r     i
class Solution {
public:
	/**
	 * @param A: an array
	 * @param S: the sum
	 * @return: the number of non-empty subarrays
	 */
	int numSubarraysWithSum(vector<int>& A, int S) {
		// Write your code here.
		int res = 0;
		if (S == 0)
		{
			int count = 0;
			for (int i = 0; i <= A.size(); i++)
			{
				if (i != A.size() && A[i] == 0) count++;
				else
				{
					res += (count + 1) * count / 2;
					count = 0;
				}
			}
			return res;
		}
		deque<int> dq;
		dq.push_back(-1);
		for (int i = 0; i <= A.size(); i++)
		{
			if (i != A.size() && A[i] == 0) continue;
			if (dq.size() > S)
			{
				int first = dq.front(); dq.pop_front();
				int second = dq.front();
				int third = dq.back();
				res += (i - third) * (second - first);

			}
			dq.push_back(i);
		}
		return res;
	}
};