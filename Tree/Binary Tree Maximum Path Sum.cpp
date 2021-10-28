// https://leetcode.com/problems/binary-tree-maximum-path-sum/





class Solution {
    
    int solve(TreeNode*root,int &ans){
        if(!root)return 0;
        int lh = solve(root->left,ans);
        int rh = solve(root->right,ans);
        ans = max(ans,lh+rh+root->val);
        return max(0,root->val+max(lh,rh));
    }
    
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        solve(root,ans);
        return ans;
    }
};
