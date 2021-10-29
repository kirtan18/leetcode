https://leetcode.com/problems/symmetric-tree/



class Solution {
    bool solve(TreeNode*k1,TreeNode*k2){
       if(k1 == NULL && k2 == NULL)return true;
       if(k1 == NULL || k2 == NULL)return false;
       
       return (k1->val == k2->val) 
              && solve(k1->left,k2->right)
              && solve(k1->right,k2->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return solve(root,root);
    }
};
