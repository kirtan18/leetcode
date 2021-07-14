  https://leetcode.com/problems/validate-binary-search-tree/
  
    ///////////////////////////////////////////  Best Method  /////////////////////////////////////////////
    
    
    class Solution {
public:
    void inOrder(TreeNode* root) {
        if (!root)
            return;
        inOrder(root->left);
        tree.push_back(root->val);
        inOrder(root->right);
    }
   
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        
        inOrder(root);
        for (int i=1; i<tree.size(); i++)
            if (tree[i] <= tree[i-1])
                return false;
        return true;
    }
private:
    vector<int> tree;
};


///////////////////////////////////////////////////  2nd  method for reduse S.C ///////////////////////////////////////////


 class Solution {
    
    bool valid(TreeNode * root, int *lower , int *upper){
         if(!root)return true;
         
         if(upper && root->val >= *upper){
             return false;
         }
        
         if(lower && root->val <= *lower){
             return false;
         }
        
         return valid(root->left,lower,&(root->val)) && 
                valid(root->right,&(root->val),upper);         
    }    
public:
    bool isValidBST(TreeNode* root) {
        return valid(root,NULL,NULL);
    }
};
