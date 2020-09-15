// 207. Interval Sum II

// 1. lowbit = x & (-x)  arr is the size of A, bit is A.size() + 1, idx from [1,n]
// 2. update itselft as well as its father  i = idx + 1; i <= n; i += lowbit(i)
// 3. query  sum up all children i = idx + 1; i > 0 ; i -= lowbit(i)


// binary indexed tree
class Solution {
private:
    vector<int> arr,bit;
public:
    /* you may need to use some attributes here */

    /*
    * @param A: An integer array
    */
    Solution(vector<int> A) {
        // do intialization if necessary
        arr = vector<int>(A.size(),0);
        bit = vector<int>(A.size()+1,0);
        for(int i = 0; i < A.size(); i++)
        {
            modify(i,A[i]);
        }
    }

    /*
     * @param start: An integer
     * @param end: An integer
     * @return: The sum from start to end
     */
    long long query(int start, int end) {
        // write your code here
        long long sum = getPresum(end) - getPresum(start - 1);
        return sum;
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

    /*
     * @param index: An integer
     * @param value: An integer
     * @return: nothing
     */
    void modify(int index, int value) {
        // write your code here
        int diff = value - arr[index];
        arr[index] = value;
        for(int i = index + 1; i <= arr.size(); i += lowbit(i))
        {
            bit[i] += diff;
        }
    }
    
    int lowbit(int x)
    {
        return x & (-x);
    }
};



//  segmentTree
class segmentTreeNode{
public:
    int start,end,sum;
    segmentTreeNode *left, *right;
    segmentTreeNode(int s, int e, int a):start(s),end(e),sum(a),left(nullptr),right(nullptr){}
};

class Solution {
private:
    segmentTreeNode* root;
    vector<int> nums;
public:
    /* you may need to use some attributes here */

    /*
    * @param A: An integer array
    */
    Solution(vector<int> A) {
        // do intialization if necessary
        root = buildTree(A,0,A.size()-1);
        nums = A;
    }
    
    segmentTreeNode* buildTree(vector<int>& A, int start, int end)
    {
        if(start > end) return nullptr;
        segmentTreeNode* cur = new segmentTreeNode(start,end,A[start]);
        if(start == end) return cur;
        int mid = (start + end)/2;
        cur->left = buildTree(A,start,mid);
        cur->right = buildTree(A,mid+1,end);
        cur->sum = cur->left->sum + cur->right->sum;
        return cur;
    }

    /*
     * @param start: An integer
     * @param end: An integer
     * @return: The sum from start to end
     */
    long long query(int start, int end) {
        // write your code here
        return queryTree(start,end,root);
    }
    
    long long queryTree(int start, int end, segmentTreeNode* root)
    {
        if(root->start == start && root->end == end) return root->sum;
        int mid = (root->start + root->end) / 2;
        if(start <= mid)
        {
            if(end <= mid)
            {
                return queryTree(start,end,root->left);
            }
            else return queryTree(start,mid,root->left) + queryTree(mid+1,end,root->right);
        }
        else return queryTree(start,end,root->right);
    }

    /*
     * @param index: An integer
     * @param value: An integer
     * @return: nothing
     */
    void modify(int index, int value) {
        // write your code here
        int diff = value - nums[index];
        nums[index] = value;
        updateTree(diff,index,root);
    }
    
    void updateTree(int diff, int idx, segmentTreeNode* root)
    {
        root->sum += diff;
        if(root->start == root->end) return;
        int mid = (root->start + root->end) / 2;
        if(idx <= mid) updateTree(diff,idx,root->left);
        else updateTree(diff,idx,root->right);
    }
};