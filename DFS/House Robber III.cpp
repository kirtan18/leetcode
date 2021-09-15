https://leetcode.com/problems/house-robber-iii/


//////////////////////////////// TLE || S.C = O(1) ///////////////////////////////////
class Solution {
public:
    int rob(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        int val = 0;
        if(root->left) val += rob(root->left->left ) +  rob(root->left->right);
        if(root->right) val += rob(root->right->left) + rob(root->right->right);
        
        return max(root->val + val , rob(root->left) + rob(root->right));
    }
};


///////////////////////////////// T.C = O(N) || S.C = O(N) ///////////////////////////////

class Solution {
public:
    map<TreeNode*,int>mp;
    int rob(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        if(mp[root])return mp[root];
        int val = 0;
        if(root->left) val += rob(root->left->left ) +  rob(root->left->right);
        if(root->right) val += rob(root->right->left) + rob(root->right->right);
        
        return mp[root] = max(root->val + val , rob(root->left) + rob(root->right));
    }
};
