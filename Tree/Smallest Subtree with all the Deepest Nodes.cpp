// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/



class Solution{
    vector<int>ans;
    unordered_map<TreeNode*,TreeNode*>parent;
    set<TreeNode*>vis;
    
    void findParent(TreeNode*root){
        if(!root)return;
        
        if(root->left){
            parent[root->left] = root;
            findParent(root->left);
        }
        
        if(root->right){
            parent[root->right] = root;
            findParent(root->right);
        }
    }
    
    void dfs(TreeNode*tar , int k){
        if(vis.find(tar) != vis.end())return;
        
        vis.insert(tar);
        
        if(k == 0){
            ans.push_back(tar->val);
            return;
        }
        
        if(tar->left)dfs(tar->left,k-1);
        if(tar->right)dfs(tar->right ,k-1);
        
        TreeNode * p = parent[tar];
        if(p)dfs(p,k-1);
    }
    
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root)return {};
        findParent(root);
        dfs(target,k);
        return ans;
    }
};
