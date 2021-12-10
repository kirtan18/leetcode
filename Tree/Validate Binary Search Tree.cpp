  https://leetcode.com/problems/validate-binary-search-tree/ 
  
///////////////////////////////////////////  Best Method  /////////////////////////////////////////////
    
    
    class Solution {
public:
    void inOrder(TreeNode* root) {
        if (!root)
            return;
        inOrder(root->left);
        tree.push_back(root->val);
        inOrder(root->right);
    }
   
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        
        inOrder(root);
        for (int i=1; i<tree.size(); i++)
            if (tree[i] <= tree[i-1])
                return false;
        return true;
    }
private:
    vector<int> tree;
};

////////////////////////////////////////////// Using BFS ///////////////////////////////////////////////////
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        queue<tuple<TreeNode*,long,long>>q;
        q.push(root,LONG_MIN,LONG_MAX);
        
        while(!q.empty()){
             TreeNode*node = get<0>(q.front());
             long lower = get<1>(q.front());
             long upper = get<2>(q,front()); 
             q.pop();
            
             if(node->val <= lower || node->val >= upper)return false;
             if(node->left != NULL) q.emplace(node->left,lower,node->val);
             if(node->right != NULL) q.emplace(node->right,node->val,upper);
        }
        return true;
    }
};

///////////////////////////////////////////////////  2nd  method for reduse S.C ///////////////////////////////////////////


 class Solution {
    
    bool valid(TreeNode * root, int *lower , int *upper){
         if(!root)return true;
         
         if(upper && root->val >= *upper){
             return false;
         }
        
         if(lower && root->val <= *lower){
             return false;
         }
        
         return valid(root->left,lower,&(root->val)) && 
                valid(root->right,&(root->val),upper);         
    }    
public:
    bool isValidBST(TreeNode* root) {
        return valid(root,NULL,NULL);
    }
};
