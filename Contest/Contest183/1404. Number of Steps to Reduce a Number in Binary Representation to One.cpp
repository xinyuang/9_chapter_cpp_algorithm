1404. Number of Steps to Reduce a Number in Binary Representation to One

int numSteps(string &s) {
    int res = 0, carry = 0;
    for (auto i = s.size() - 1; i > 0; --i) {
        ++res;
        if (s[i] - '0' + carry == 1) {
            carry = 1;
            ++res;
        }
    }
    return res + carry;
}

class Solution {
public:
    int numSteps(string s) {
        int carry = 0;
        if(s.size() == 0) return 0;
        int step = 0;
        for(int i = s.size()-1; i>0; i--)
        {
            int cur = carry + s[i] - '0';
            if(cur % 2 == 1) 
            {
                step += 2;
            }
            else step++;
            carry = (cur % 2 || cur == 2);
        }
        return step + carry;
    }
};