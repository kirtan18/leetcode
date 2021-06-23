// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/



class Solution {
    int sum = 0;
    void convertSum( TreeNode *root){
        if(!root)return;
        if(root->right)convertSum(root->right);
        root->val = (sum += root->val);
        if(root->left)convertSum(root->left);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
         convertSum(root);
         return root; 
    }
};
