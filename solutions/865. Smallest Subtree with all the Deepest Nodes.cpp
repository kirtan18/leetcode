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
// time = O(n)  space = O(1)
class Solution {
public:
    int getdepth(TreeNode* root){
      if(!root)return {};
        
        int ld = getdepth(root->left);
        int rd = getdepth(root->right);
        
        return 1+max(ld,rd);        
    }    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
       
      if(!root) return {};
        
        int left = getdepth(root->left);
        int right= getdepth(root->right);
        
        if(left == right) return root;
        
        if(left > right) return subtreeWithAllDeepest(root->left);
        else return subtreeWithAllDeepest(root->right);
                
    }
