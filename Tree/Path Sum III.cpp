https://leetcode.com/problems/path-sum-iii/


//////////////////////////////////////////////////////// using DFS || T.C = O(N^2) || S.C = O(1)  //////////////////////////////////////////////////

class Solution {
public:
    int ans = 0;
    
    void dfs(TreeNode * root, int sum){
        if(!root)return;
        if(root->val == sum)ans++;
        dfs(root->left,sum-root->val);
        dfs(root->right,sum-root->val);
    }
       
    int pathSum(TreeNode* root, int targetSum) {
        if(root){
            dfs(root,targetSum);
            pathSum(root->left,targetSum);
            pathSum(root->right,targetSum);
        }
        return ans;
    }
};


///////////////////////////////////////////////////////  DFS  || T.C = O(H)  || S.C = O(N)  //////////////////////////////////////////////////

class Solution {
    int ans = 0, sum;
    vector<int>vis = {0};
    
    void dfs(TreeNode * root , int partSum = 0){
        partSum += root->val;
        
        for(auto it : vis) if( it == partSum - sum )ans++;
        vis.push_back(partSum);
        
        if(root->left)dfs(root->left , partSum);
        if(root->right)dfs(root->right , partSum);
        
        vis.pop_back();
    }
    
    
public:
    int pathSum(TreeNode* root, int targetSum) {
        sum = targetSum;
        if(!root)return ans;
        dfs(root);
        return ans;
    }
};
