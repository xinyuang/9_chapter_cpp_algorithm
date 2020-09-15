// 840. Range Sum Query - Mutable

// 1. segment tree + vector<int> A, update diff, query range
// 1. Binary indexed tree

class segmentTreeNode{
public:
    int start;
    int end;
    int sum;
    segmentTreeNode* left, *right;
    segmentTreeNode(int s, int e, int a):start(s),end(e),sum(a),left(nullptr),right(nullptr){}
};

class NumArray {
private:
    segmentTreeNode* root;
    vector<int> A;
public:
    NumArray(vector<int> nums) {
        A = nums;
        root = buildTree(nums,0,A.size()-1);
        // traverse(root);
    }

    void update(int i, int val) {
        int diff = val - A[i];
        A[i] = val;
        updateTree(diff,i,0,A.size() - 1, root);
    }
    
    int sumRange(int i, int j) {
        return querySum(root, i, j);
    }
    
    segmentTreeNode* buildTree(vector<int>& nums, int start, int end)
    {
        if(start > end) return nullptr;
        segmentTreeNode* node = new segmentTreeNode(start,end,nums[start]);
        if(start == end)
        {
            return node;
        }
        int mid = (start + end)/2;
        node->left = buildTree(nums,start,mid);
        node->right = buildTree(nums,mid+1,end);
        node->sum = node->left->sum + node->right->sum;
        return node;
    }
    
    int querySum(segmentTreeNode* root, int start, int end)
    {
        if(root->start == start && root->end == end)
        {
            return root->sum;
        }
        int mid = (root->start + root->end)/2;
        if(mid >= start)
        {
            if(end <= mid)
            {
                return querySum(root->left, start, end);
            }
            else
            {
                return querySum(root->left,start,mid) + querySum(root->right,mid+1,end);
            }
        }
        else
        {
            return querySum(root->right, start, end);
        }
    }
    
    void updateTree(int diff, int tar, int start, int end, segmentTreeNode* root)
    {
        if(root->start == root->end)
        {
            if(root->start == tar) root->sum += diff;
            return;
        }
        if(root->start <= tar && root->end >= tar) root->sum += diff;
        int mid = (root->start + root->end) / 2;
        if(mid < tar)
        {
            updateTree(diff, tar, mid + 1, end, root->right);
        }
        else
        {
            updateTree(diff, tar, start, mid, root->left);
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */