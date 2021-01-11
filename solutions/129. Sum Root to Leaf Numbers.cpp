/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 // time = O(n)  ,, space = O(1)
​
class Solution {
public:
    
    int helper(TreeNode* root ,int sum){
        if(!root) return 0;
        
        sum = sum * 10 + root->val;
        
        if(root -> left == NULL && root -> right == NULL) return sum;
        
        int ans = helper(root->left , sum) + helper(root->right , sum);
        
        return ans;
        
    }
    
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        return helper(root , sum);
    }
};
​
