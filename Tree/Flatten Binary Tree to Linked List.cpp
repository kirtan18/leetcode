https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

//////////////////////////////////////////////////////////////  Recusive || T.C = O(N) || S.C = O(N)  //////////////////////////////////////////////////

class Solution {
    TreeNode * head = NULL;
    
    void revpre(TreeNode * node){
        if(node->right) revpre(node->right);
        if(node->left) revpre(node->left);
        node->left = NULL;
        node->right = head;
        head = node;
    }
    
public:
    void flatten(TreeNode* root) {
        if(root) revpre(root);
    }
};


///////////////////////////////////////////////////  Without Space || T.C = O(N)  || S.C = O(1) || moris algo  //////////////////////////////////////////////

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode * curr = root;
        while(curr){
            if(curr->left){
                TreeNode * runner = curr->left;
                while(runner->right){
                    runner = runner->right;
                }
                runner->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};
