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
               // time : O(n)   space : O(n);   optimal  is  below
#include<bits/stdc++.h>
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
     
          if(d == 1){
            TreeNode* newroot = new TreeNode(v);
            newroot->left = root;
            return newroot;
         } 
     
        queue<TreeNode*>que;
        que.push(root);
        int depth = 1;
        
        while(!que.empty()){
           
            int size = que.size();
            
            for(int i=0 ; i<size ; i++ ){
                TreeNode* top = que.front();que.pop(); 
                
