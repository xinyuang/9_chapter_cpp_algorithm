453. Flatten Binary Tree to Linked List

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void flatten(TreeNode * root) {
        // write your code here
        flattenList(root);
    }
    
    TreeNode* flattenList(TreeNode* root)
    {
        if(!root) return nullptr;
        TreeNode* left = flattenList(root->left);
        TreeNode* right = flattenList(root->right);
        TreeNode* tmpLeft = root->left;
        TreeNode* tmpRight = root->right;
        
        if(left) {
            left->right = tmpRight;
            root->right = tmpLeft;
            root->left = nullptr;
        }
        if(right){
            return right;
        } 
        if(left){
            return left;
        }
        return root;
    }
};

class Solution {
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void flatten(TreeNode * root) {
        // write your code here
        while(root)
        {
            if(root->left)
            {
                TreeNode* cur = root->left;
                while(cur->right) cur = cur->right;
                cur->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
            root = root->right;
        }
    }
};