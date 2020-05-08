1398. K Decimal Addition

class Solution {
public:
    /**
     * @param k: The k
     * @param a: The A
     * @param b: The B
     * @return: The answer
     */
    string addition(int k, string &a, string &b) {
        // Write your code here
        for(int i = 0; i < a.size(); i++)
        {
            if(a[i] != '0')
            {
                a = a.substr(i);
                break;
            }
        }
        for(int i = 0; i < b.size(); i++)
        {
            if(b[i] != '0')
            {
                b = b.substr(i);
                break;
            }
        }
        if(a.size() < b.size()) swap(a,b);
        int j = b.size()-1;
        int carry = 0;
        for(int i = a.size() - 1; i >= 0; i--)
        {
            int sum = a[i] - '0';
            if(j >= 0)
            {
                sum += b[j] - '0';
                j--;
            }
            sum += carry;
            a[i] = sum % k + '0';
            carry = sum / k;
        }
        string prefix = "";
        if(carry != 0) prefix.push_back(carry + '0');
        return prefix + a;
    }
};