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
      bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int size=q.size(), n=-1;
            for(int i=0;i<size;i++) {
                TreeNode* cur=q.front();
                if(level%2==0) {
                    if(cur->val%2==0) return false;
                    if(cur->val<=n) return false;
                }
                else {
                    if(cur->val%2!=0) return false;
                    if(n>0&&cur->val>=n) return false;
                }
                n=cur->val;
                q.pop();
                if(cur->left!=NULL) q.push(cur->left);
                if(cur->right!=NULL) q.push(cur->right);
            }
            level++;
