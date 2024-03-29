/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
​
//    time : O(H)  space : O(1);
​
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if(root == NULL) return true;
        
        
        if(root->left != NULL)
            if(root->left->val != root->val) return false;
        
        if(root->right != NULL)
            if(root->right->val != root->val) return false;
        
        
        
     return isUnivalTree(root->left) && isUnivalTree(root->right); 
        
    }
};
