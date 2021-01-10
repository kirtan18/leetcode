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
class FindElements {
public:
    // time = O(n)  space = O(n)
    
    set<int>set;
    void DFS (TreeNode* root){
        if(!root) return;
        
        int cur = root->val;
        set.insert(cur);
        
        if(root->left){
            root->left->val = cur * 2 +1;
        }
        if(root->right){
            root->right->val = cur *2 + 2;
        }
        DFS(root->left);
        DFS(root->right);
        
    }
    
    FindElements(TreeNode* root) {
        root->val = 0;
