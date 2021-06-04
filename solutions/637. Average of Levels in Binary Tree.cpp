// *** using DFS ***//
​
class Solution {
    pair<double,int>layer[1000];
    int pos = 0;
    
    void dfs(TreeNode* root , int depth = 0){
        layer[depth].first += root->val , layer[depth].second++;
        
        pos = max(pos,depth);
        
        if(root->left)dfs(root->left , depth+1);
        if(root->right)dfs(root->right , depth+1);
    }  
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root)return {};
        dfs(root);
        vector<double>ans(++pos);
        
        while(pos--){
            ans[pos] = (layer[pos].first / layer[pos].second);
        }
        return ans;
    }
};
​
​
​
​
​
​
