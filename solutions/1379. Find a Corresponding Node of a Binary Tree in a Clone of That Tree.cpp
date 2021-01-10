/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
​
// time == O(n)   space == O(1)
class Solution {
public:
    TreeNode * res;
    void inordered(TreeNode*original ,TreeNode* cloned,TreeNode* target){
        if(!original)return;
            inordered(original->left,cloned->left,target);
             if(original == target)
                 res = cloned;  
             inordered(original->right,cloned->right,target);             
        
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        inordered(original,cloned,target);
        return res;
        
    }
};
