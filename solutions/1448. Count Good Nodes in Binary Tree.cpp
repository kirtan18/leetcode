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
    
   
    // time = O(N) , space = O(1)
    int maxi= 0;
    void helper(TreeNode* root,int high){
        if(!root)return ;
          
        if(root->val >= high){
            maxi++;
            high = root->val;
        }
     //   high = max(high,root->val);
        
        helper(root->left,high);
        helper(root->right,high);   
    }
    
    int goodNodes(TreeNode* root) {
        
        if(!root)return NULL;
        int high = root->val;
    
