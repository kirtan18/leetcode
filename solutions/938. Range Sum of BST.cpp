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
    
    // without any extra space only use recursion
    
    int sum = 0;
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root)return NULL;
        if(root->val >= low && root->val <= high){
            sum += root->val;
        }
            rangeSumBST(root->left,low,high);
            rangeSumBST(root->right,low,high);
        
        
       return sum; 
    }
        
};
   
////////// ************// with extra space      ********************///// 
​
    /*
    vector<int>ans;
    void helper(TreeNode* root, int low, int high){
        if(!root)return;
        
        helper(root->left,low,high);
        ans.push_back(root->val);
        helper(root->right,low,high);
    }
    
      int rangeSumBST(TreeNode* root, int low, int high) {
          
           helper(root,low,high);
           int sum =0;
           int i;
           for( i=0;i<ans.size();i++){
               if(ans[i] == low){
                   break;
               }
           }
         do{
             sum += ans[i];
         }while(ans[i++] != high);
          return sum;
      }
    */
    
​
