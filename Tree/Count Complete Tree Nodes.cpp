// Given the root of a complete binary tree, return the number of the nodes in the tree.

// According to Wikipedia, every level, except possibly the last, 
// is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible.
//   It can have between 1 and 2h nodes inclusive at the last level h.

// Design an algorithm that runs in less than O(n) time complexity.



Example 1:
Input: root = [1,2,3,4,5,6]
Output: 6
  
Example 2:
Input: root = []
Output: 0
  
Example 3:
Input: root = [1]
Output: 1
  
  
//   ////////////////////////////////////////////  Using BST Property ////////////////////////////////////////////////
  class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        
        int left_level = 1;
        TreeNode * l = root->left;
        
        while(l){
            l = l->left;
            left_level++;
        }
        
        int right_level = 1;
        TreeNode * r = root->right;
        
        while(r){
            r = r->right;
            right_level++;
        }
        
        if(left_level == right_level){
            return pow(2,left_level) - 1;
        }
        
        return 1 + countNodes(root->left) + countNodes(root->right);
        
    }
};
