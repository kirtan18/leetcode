// https://leetcode.com/problems/trim-a-binary-search-tree/


// Example 1:
// Input: root = [1,0,2], low = 1, high = 2
// Output: [1,null,2]
// Example 2:


// Input: root = [3,0,4,null,2,null,null,1], low = 1, high = 3
// Output: [3,2,null,1]
// Example 3:

// Input: root = [1], low = 1, high = 2
// Output: [1]
// Example 4:

// Input: root = [1,null,2], low = 1, high = 3
// Output: [1,null,2]
// Example 5:

// Input: root = [1,null,2], low = 2, high = 4
// Output: [2]



class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root)return NULL;
        
        if(root->val > high)return trimBST(root->left,low,high);
        if(root->val < low) return trimBST(root->right,low,high);
        
        root->left = trimBST(root->left,low,high);
        root->right = trimBST(root->right,low,high);
        
        return root;
        
    }
};
