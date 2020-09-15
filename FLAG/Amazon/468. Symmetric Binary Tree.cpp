// 468. Symmetric Binary Tree


class Solution {
public:
    /**
     * @param root: the root of binary tree.
     * @return: true if it is a mirror of itself, or false.
     */
    bool isSymmetric(TreeNode * root) {
        // write your code here'
        if(!root) return true;
        bool res = checkSymmetric(root->left,root->right);
        return res;
    }
    
    bool checkSymmetric(TreeNode* left, TreeNode* right)
    {
        if(!left && !right) return true;
        if((left && !right) || (!left && right)) return false;
        if(left->val != right->val) return false;
        return checkSymmetric(left->left,right->right) && checkSymmetric(left->right,right->left);
    }
};