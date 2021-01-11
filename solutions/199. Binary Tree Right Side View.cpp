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
class Solution {
public:
    void rightviewHelper(TreeNode *root , int level , int *max , vector<int>& v){
    if(root == NULL) 
        return;
    
    if(*max < level){
        v.push_back(root->val);
        *max = level;
    }
    
   
    rightviewHelper(root->right , level+1 , max , v);
    rightviewHelper(root->left , level+1 , max , v);    
    
}
    
    vector<int> rightSideView(TreeNode* root) { 
        
     vector<int> v;
     int max=0;
     rightviewHelper(root,1,&max,v);
     return v;
    }
