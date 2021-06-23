// https://leetcode.com/problems/convert-bst-to-greater-tree/


// Example 1:
// Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
// Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]

// Example 2:
// Input: root = [0,null,1]
// Output: [1,null,1]

// Example 3:
// Input: root = [1,0,2]
// Output: [3,3,2]

// Example 4:
// Input: root = [3,2,4,1]
// Output: [7,9,4,10]


class Solution {
    int sum = 0;
    void convertSum( TreeNode *root){
        if(!root)return;
        if(root->right)convertSum(root->right);
        root->val = (sum += root->val);
        if(root->left)convertSum(root->left);
    }
    
public:
    TreeNode* convertBST(TreeNode* root) {
       convertSum(root);
       return root; 
    }
};
