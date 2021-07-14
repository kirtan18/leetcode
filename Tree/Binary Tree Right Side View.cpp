https://leetcode.com/problems/binary-tree-right-side-view/


class Solution {
    vector<int>ans;
    void solve(TreeNode * root , int *max , int level){        
        if(!root)return;        
        if(*max < level){
           ans.push_back(root->val);
           *max = level;            
        }        
        solve(root->right,max,level+1);
        solve(root->left,max,level+1);        
    }
      
public:
    vector<int> rightSideView(TreeNode* root) {
        int max = 0;      
        solve(root,&max,1);   
        return ans;
    }
};
