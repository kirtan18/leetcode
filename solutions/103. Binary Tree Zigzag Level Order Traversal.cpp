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
// time = O(n)  space = O(n)
#include<bits/stdc++.h>
class Solution {
public:
     vector<vector<int>>ans;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return  {};
        
        stack<TreeNode*>s1;
        stack<TreeNode*>s2;
        vector<int>temp;
        s1.push(root);
        int k = 0;
        
        while(!s1.empty() || !s2.empty()){
            
           if(k%2 == 0){ 
            while(!s1.empty()){
              TreeNode*curr = s1.top(); s1.pop();
                temp.push_back(curr->val);
                if(curr->left) s2.push(curr->left);
                if(curr->right) s2.push(curr->right);
              }
               k++;
