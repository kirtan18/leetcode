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
// time = O(logn * logn)
class Solution {
public:
    // by defination
    
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        int left_level = 1;
        TreeNode*l =root->left;
        
        while(l){
            l = l->left;
            left_level++;
        }
        
        int right_level = 1;
        TreeNode*r = root->right;
        
        while(r){
            r =r->right;
            right_level++;
        }
        
