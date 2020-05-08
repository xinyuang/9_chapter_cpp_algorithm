// 722. Maximum Subarray VI
// 1. F[0,l] ^ F[0,r] = F[[l,r]   where F[i,j] is xor from element i to j
// 2. do a for loop to store prefix F[0,i] in the trie
// 3. find the max candidate X in the trie that maximize X^F[0,i]

class TrieNode{
public:
    TrieNode* next[2];
    int prefix;
    TrieNode(){
        next[0] = nullptr;
        next[1] = nullptr;
    }
};

class Solution {
public:
    /**
     * @param nums: the array
     * @return: the max xor sum of the subarray in a given array
     */
    int maxXorSubarray(vector<int> &nums) {
        // write code here
        TrieNode* root = new TrieNode();
        int prefix = 0;
        int max_res = INT_MIN;
        addNode(root,0);
        for(int i = 0; i < nums.size(); i++)
        {
            prefix ^= nums[i];
            addNode(root,prefix);
            int next_max = search(root,prefix);
            max_res = max(max_res,next_max);
        }
        return max_res;
    }
    
    void addNode(TrieNode* root, int prefix)
    {
        TrieNode* cur = root;
        for(int i = 32-1; i>= 0; i--)
        {
            bool next = prefix & (1 << i);
            if(!cur->next[next]) cur->next[next] = new TrieNode();
            cur = cur->next[next];
        }
        cur->prefix = prefix;
    }
    
    int search(TrieNode* root, int prefix)
    {
        TrieNode* cur = root;
        for(int i = 32 - 1; i >= 0; i--)
        {
            bool target = !(prefix & (1 << i));
            if(cur->next[target]) cur = cur->next[target];
            else if(cur->next[1-target]) cur = cur->next[1-target];
        }
        return prefix ^ (cur->prefix);
    }
};