https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

class Solution {
  public:
    vector <int> bottomView(Node *root) {
         if(!root)return {};    
       map<int,int>mp;
       queue<pair<Node*,int>>q;
       vector<int>ans;
       q.push({root,0});
       
       while(!q.empty()){
           auto it = q.front();
           q.pop();
           auto node = it.first;
           int line = it.second;
           mp[line] = node->data;
           if(node->left){
               q.push({node->left,line-1});
           }
           if(node->right){
               q.push({node->right,line+1});
           }
       }
       for(auto it:mp){
           ans.push_back(it.second);
       }
       return ans;
    }
};
