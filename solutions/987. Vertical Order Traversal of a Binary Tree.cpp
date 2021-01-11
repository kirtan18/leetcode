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
 
         /////***********  BFS  ************/////////////   
  
 //////////*******  time = O(nlog(3)n)  ,,, space  == O(n) ************///////////     
​
class Solution {
public:
 
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        TreeNode*curr;
        queue<pair<int,TreeNode*>>q;
        q.push({0,root});
        vector<vector<int>>ans;
        map<int ,vector<int>>mymap;
        
        while(!q.empty()){
            int size = q.size();
            map<int,set<int>>mapset;
            
            while(size--){
             int col = q.front().first;
              curr   = q.front().second;
                q.pop();
                
