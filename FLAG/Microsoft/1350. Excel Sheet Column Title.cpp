// 1350. Excel Sheet Column Title
// (n-1)%26, n = (n-1)/26, reverse

class Solution {
public:
    /**
     * @param n: a integer
     * @return: return a string
     */
    string convertToTitle(int n) {
        // write your code here
        string res = "";
        while(n != 0)
        {
            char next = (n-1) % 26 + 'A';
            res.push_back(next);
            n = (n-1) /26;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};