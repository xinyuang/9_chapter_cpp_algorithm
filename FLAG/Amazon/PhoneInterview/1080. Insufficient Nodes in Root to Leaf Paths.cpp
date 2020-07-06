// 1080. Insufficient Nodes in Root to Leaf Paths

// 1. TreeNode* res = dfs(root, limit)
// 2. if(!root) return nullptr,  if(leaf) if(leaf < limit) return nullptr else return root
// 3. root->left = dfs(root->left, limit - root->val)   root->right = dfs(root->right, limit - root->val)

class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if(!root) return nullptr;
        if(!root->left && !root->right)
        {
            if(root->val < limit) return nullptr;
            return root;
        }
        root->left = sufficientSubset(root->left,limit - root->val);
        root->right = sufficientSubset(root->right, limit - root->val);
        if(!root->left && !root->right) return nullptr;
        return root;
    }
};