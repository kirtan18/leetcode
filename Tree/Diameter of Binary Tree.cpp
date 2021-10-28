https://leetcode.com/problems/diameter-of-binary-tree/

/////////////////////////////  Brute || T.C = O(N^2) ///////////////////////////////////////


class Solution {
    int depth(TreeNode*root){
        if(!root)return 0;
        else{
            return max(depth(root->left) , depth(root->right)) + 1;
        }
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        
        int longestPath = depth(root->left) + depth(root->right);   
        
        return max(longestPath,max(diameterOfBinaryTree(root->left) ,
                                   diameterOfBinaryTree(root->right)));   
    }
};

//////////////////////////////// Optimal || T.C =  O(N) ///////////////////////////////////

class Solution {
    
    int solve(TreeNode*root,int &maxi){
        if(!root)return 0;
        
        int lh = solve(root->left,maxi);
        int rh = solve(root->right,maxi);
        
        maxi = max(maxi,lh+rh);
        return 1 + max(lh,rh);
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
         int maxi = 0;
         solve(root,maxi);
         return maxi;
    }
};
