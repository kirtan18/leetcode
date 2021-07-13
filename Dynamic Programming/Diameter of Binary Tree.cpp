https://leetcode.com/problems/diameter-of-binary-tree/

//////////////////////////////////////////////  Brute Force || T.C = O(N^2) || S.C = O(1)  /////////////////////////////////////////////////

 class Solution {
public:
    
    int depth(TreeNode* root){
        if(!root)return 0;
        return max(depth(root->left) , depth(root->right)) + 1;   
    } 
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        int longestPath = depth(root->left) + depth(root->right);
        return max(longestPath , max( diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));      
    }
};



//////////////////////////////////////// Optimal || T.C = O(N) || S.C = O(1)  ////////////////////////////////////////////////////////

class Solution {
    
    int solve(Node *root , int &res){
        
        if(root == NULL) return 0;          
        int l = solve(root->left,res);
        int r = solve(root->right,res);        
        res = max(res,1+l+r);
        return 1 + max(l,r);   
    }
  
  public:
    int diameter(Node* root) {
        int res = INT_MIN;
         solve(root,res);
         return res;
    }
};
