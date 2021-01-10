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
#include<queue>
class Solution {
public:
   // time comp : O(n)  space : O(h) 
    
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        
        // using queue
        queue<TreeNode*>que;
        que.push(root);
        
        while(!que.empty()){
            int size = que.size();
            double sum = 0;
            
           for(int i = que.size(); i > 0;i--){
                auto front = que.front(); que.pop();
                
                sum += front->val;
                
                if(front->left) que.push(front->left);
                if(front->right) que.push(front->right);
            }
