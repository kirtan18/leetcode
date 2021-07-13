https://leetcode.com/problems/binary-tree-maximum-path-sum/



class Solution {
    int MaximumSum(TreeNode * root, int &res){
        if(!root)return 0;
        int l = MaximumSum(root->left,res);
        int r = MaximumSum(root->right,res);
        int temp = max(max(l,r)+root->val , root->val);
        int ans = max(temp,l+r+root->val);        
        res = max(res,ans);
        return temp;
    }
    
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        MaximumSum(root,res);
        return res;
    }
};
