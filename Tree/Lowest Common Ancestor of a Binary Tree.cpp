/////////////////////////////////////////////   Time : O(N)  space = O(1) //////////////////////////////////////////



class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return 0;
        
        if(p->val == root->val || q->val == root->val){
            return root;
        }
        
        TreeNode * lt = lowestCommonAncestor(root->left,p,q);
        TreeNode * rt = lowestCommonAncestor(root->right,p,q);
        
        if(lt == NULL)return rt;
        if(rt == NULL)return lt;
        
        return root;
        
    }
};
