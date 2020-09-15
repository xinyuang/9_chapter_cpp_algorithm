// 206. Interval Sum

// 1. lowbit = x & (-x)  arr is the size of A, bit is A.size() + 1, idx from [1,n]
// 2. update itselft as well as its father  i = idx + 1; i <= n; i += lowbit(i)
// 3. query  sum up all children i = idx + 1; i > 0 ; i -= lowbit(i)

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
private:
    vector<int> bit,arr;
public:
    /**
     * @param A: An integer list
     * @param queries: An query list
     * @return: The result list
     */
    vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        bit = vector<int>(A.size()+1,0);
        arr = vector<int>(A.size(),0);
        for(int i = 0; i < A.size(); i++)
        {
            updateTree(A[i],i);
        }
        vector<long long> res;
        for(int i = 0; i < queries.size(); i++)
        {
            long long curSum = getPresum(queries[i].end) - getPresum(queries[i].start - 1);
            res.push_back(curSum);
        }
        return res;
    }
    
    void updateTree(int val, int idx)
    {
        int diff = val - arr[idx];
        arr[idx] = val;
        for(int i = idx + 1; i <= arr.size(); i += lowbit(i))
        {
            bit[i] += diff;
        }
    }
    
    long long getPresum(int idx)
    {
        long long sum = 0;
        for(int i = idx + 1; i > 0; i -= lowbit(i))
        {
            sum += bit[i];
        }
        return sum;
    }
    
    int lowbit(int x)
    {
        return x & (-x);
    }
};


// presum immutable

class Solution {
public:
    /**
     * @param A: An integer list
     * @param queries: An query list
     * @return: The result list
     */
    vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        vector<long long> presum(A.size()+1,0);
        for(int i = 0; i < A.size(); i++) presum[i+1] = presum[i] + A[i];
        vector<long long> res;
        for(int i = 0; i < queries.size(); i++)
        {
            res.push_back(presum[queries[i].end+1] - presum[queries[i].start]);
        }
        return res;
    }
};