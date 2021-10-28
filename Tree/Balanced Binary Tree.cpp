https://leetcode.com/problems/balanced-binary-tree/

///////////////////////////////////// Brute || T.C = O(N^2) || S.C = O(1) /////////////////////////////


class Solution {
    int height(TreeNode*root){
        if(!root)return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        if(lh >= rh){
            return lh+1;
        }
        return rh+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        if(isBalanced(root->left) == false){
            return false;
        }
        if(isBalanced(root->right) == false){
            return false;
        }
        
        int lh = height(root->left);
        int rh = height(root->right);
        if(abs(lh-rh) > 1)return false;
        return true;
    }
};

///////////////////////////// Optimal || T.C = O(N) || S.C = O(1) //////////////////////////////////////////


class Solution {
    int solve(TreeNode*root){
        if(!root)return 0;
        
        int lh = solve(root->left);
        if(lh == -1)return -1;
            
        int rh = solve(root->right);
        if(rh == -1)return -1;
        
        if(abs(lh-rh) > 1)return -1;
        return max(lh,rh)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(solve(root) != -1){
            return true;
        }
        return false;
    }
};
