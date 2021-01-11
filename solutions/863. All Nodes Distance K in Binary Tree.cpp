/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    map<TreeNode*,TreeNode*> parent;
    set<TreeNode*> visit;
    
    void findparent(TreeNode* root){
         if(!root)return;
         
         if(root->left){
             parent[root->left] = root;
             findparent(root->left);
         }
         if(root->right){
             parent[root->right] = root;
             findparent(root->right);
         }
         
    }
    
    void dfs( TreeNode* target, int K){
        if(visit.find(target) != visit.end()) return;
        visit.insert(target);
        
        if(K == 0){
            ans.push_back(target->val);
            return;
        }
        
        if(target->left) dfs(target->left,K-1);
        if(target->right) dfs(target->right,K-1);
        
        TreeNode* p = parent[target];
        
        if(p) dfs(p,K-1);
    }
​
