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
class Solution {
public:
    int depth(TreeNode* root){
        if(!root)   return 0;
        
        else  return max(depth(root->left), depth(root->right)) + 1;
    }
    
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)   return 0;
        
        int longestPath = depth(root->left) + depth(root->right);
        
        return max(longestPath,
               max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));
    }
    
};
