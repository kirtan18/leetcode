https://leetcode.com/problems/binary-tree-pruning/

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(!root)return {};
        root->left =  pruneTree(root->left);
        root->right = pruneTree(root->right);
        
        if(root->val == 0 && root->left == NULL && root->right == NULL){
            return NULL;
        }
        return root;
    }
};
