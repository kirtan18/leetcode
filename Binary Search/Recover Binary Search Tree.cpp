https://leetcode.com/problems/recover-binary-search-tree/

class Solution {
    
    TreeNode * prev = new TreeNode(INT_MIN);
    TreeNode*first = NULL;
    TreeNode*second = NULL;
    void inorder(TreeNode * root){
        if(!root)return;
        inorder(root->left);
        
        if(first == NULL && prev->val > root->val){
            first = prev;
        }
        
        if(first != NULL && prev->val > root->val){
            second = root;
        }
        prev = root;
        inorder(root->right);
    }
    
public:
    void recoverTree(TreeNode* root) {
       
        inorder(root);
        
        int temp = first->val;
        first->val = second->val;
        second->val = temp;    
    }
};
