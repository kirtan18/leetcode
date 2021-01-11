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
    vector<vector<int>> ret;
    vector<vector<int>> levelOrder(TreeNode* root) {
      if(!root)return {};
      queue<TreeNode*>que;
      vector<int>temp;
      que.push(root);  
      
      while(!que.empty()){
          
          int n = que.size();
          
          for(int i=0;i<n;i++){
              TreeNode*cur = que.front();
              temp.push_back(cur->val);
              que.pop();
              
              
              if(cur->left) que.push(cur->left);
              if(cur->right) que.push(cur->right);
          }
          ret.push_back(temp);
