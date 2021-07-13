https://practice.geeksforgeeks.org/problems/maximum-path-sum/1#


class Solution {
    
    int solve(Node * root , int &res){
        if(!root)return 0;
        if(!root->left && !root->right)return root->data;
        
        int l = solve(root->left,res);
        int r = solve(root->right,res);
        
        if(root->left && root->right){
    
             res = max(res,l+r+root->data);
             return root->data + max(l,r);
        }
        
        return (!root->left)? r + root->data 
                             : l + root->data;
        
    }
    
public:
    int maxPathSum(Node* root)
    {
        int res = INT_MIN;
        int val = solve(root, res);
        if(res == INT_MIN){
          return val;
        }
        return res;
    }
};
