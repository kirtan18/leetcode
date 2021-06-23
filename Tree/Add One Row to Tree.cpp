// https://leetcode.com/problems/add-one-row-to-tree/


//////////////////////////////////////////////////////////   BFS ///////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1){
            TreeNode * newroot = new TreeNode(v);
            newroot->left = root;
            return newroot;
        }
        
        queue<TreeNode*>q;
        q.push(root);
        int depth = 1;
        
        while(!q.empty()){
            int size = q.size();
            for(int  i = 0 ; i < size ; i++){
                TreeNode * top = q.front();
                q.pop();
                if(depth == d-1){
                    TreeNode * left = new TreeNode(v);
                    TreeNode * right = new TreeNode(v);
                    
                    if(top->left != NULL){
                        left->left = top->left;
                    }
                    if(top->right != NULL){
                        right->right = top->right;
                    }
                    
                    top->left = left;
                    top->right = right;
                    continue;
                }
                
                if(top->left != NULL)q.push(top->left);
                if(top->right!= NULL)q.push(top->right);
                
            }
            depth++;
        }
        
        return root;
    }
};

/////////////////////////////////////////////////////////////////// DFS //////////////////////////////////////////////////////////////////


class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v , int d) {
        if(d == 1)return new TreeNode(v,root,NULL);
        else if(d == 2){
            root->left = new TreeNode(v,root->left,NULL);
            root->right = new TreeNode(v,NULL,root->right);
        }
        else{
           if(root->left)addOneRow(root->left,v,d-1);
           if(root->right)addOneRow(root->right,v,d-1);
        }
        return root;
    }
};
















