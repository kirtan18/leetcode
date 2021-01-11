//  this  method  is  sol  is  time : O(n) and  space : O(n);
//  optimal solution is  below  space: O(1);
​
#include<unordered_map>
​
/*
class Solution {
public:
    
    void dfs(TreeNode* root,unordered_map<int,int>& map){
        
        if(root == NULL)return;
        
        map[root->val]++;
        dfs(root->left,map);
        dfs(root->right,map);        
    }
    
    
    vector<int> findMode(TreeNode* root) {
        
        if(root == NULL)return {};
        unordered_map<int,int>map;
        dfs(root,map);
        vector<int>a;
        int max = 0;
        
        for(auto i : map){
            if(i.second > max){
                a.clear();
                max = i.second;
            }
            if(i.second >= max){
                a.push_back(i.first);
            }
