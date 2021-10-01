
https://leetcode.com/problems/invert-binary-tree/submissions/

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)return NULL;
        TreeNode*temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
   }
};

//////////////////////////////////////////////////////////////////////////////

DFS:

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

//////////////////////////////////////////////////////////////////////////
BFS

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;        
        queue<TreeNode*> q{{root}}; 
        while(!q.empty()){
            auto node = q.front();q.pop();            
            swap(node->left, node->right);
            for(auto& e: {node->left, node->right}) if(e) q.push(e);                   
        }
        return root;
    }
};

