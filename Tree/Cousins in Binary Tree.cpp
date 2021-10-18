https://leetcode.com/problems/cousins-in-binary-tree/


//////////////////////////////////////////    BFS      //////////////////////////////////////////////

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int n=q.size();
             bool f1=false,f2=false;
            for(int i=0;i<n;i++){
                TreeNode*tmp=q.front();
                q.pop();
                //if values found
                if(tmp->val==x) f1=true;
                if(tmp->val==y) f2=true;
                
                //checking if parent is same
                if(tmp->left && tmp->right){
                if((tmp->left->val==x && tmp->right->val==y)|| (tmp->left->val==y && tmp->right->val==x))
                    return false;
                }
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }
            if(f1&&f2)
                return true;
        }
        
        return false;
    }
};

//////////////////////////////   DFS   ////////////////////////////////////////


class Solution {
public:
    
    int xDepth , xParent , yDepth , yParent;
    
    void helper(TreeNode * root,int x, int y , int dep , int par_val){
        
        if(!root)return;
        
        if(root->val ==  x){
            xDepth = dep;
            xParent = par_val;
            return; 
        }
        
        if(root->val == y){
            yDepth = dep;
            yParent = par_val;
            return;
        }
        
        helper(root->left,x,y,dep+1,root->val);
         helper(root->right,x,y,dep+1,root->val);
        
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val == x || root->val == y)return false;
        
        helper(root,x,y,0,0);
        
        if(xDepth == yDepth && xParent != yParent){
            return true;
        }
        return false;
    }
};
