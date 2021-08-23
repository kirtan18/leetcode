https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

///////////////////////////////////////////////////// Using Set /////////////////////////////////////////////

class Solution {
public:
    unordered_set<int>s;
    
    bool findTarget(TreeNode* root, int k) {
       if(!root)return false;
       if(s.count(k - root->val)) return true;
       s.insert(root->val);
       return findTarget(root->left,k) || findTarget(root->right,k);
    }
};


////////////////////////////////////////////////// Using inorder Traversal /////////////////////////////////////////


class Solution {
    vector<int>v;
    void inorder(TreeNode * root){
        if(!root)return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)return false;
        inorder(root);
        int i = 0 , j = v.size()-1;
        
        while(i<j){
            int sum = v[i] + v[j];
            if(sum == k){
                return true;
            }
            else if(sum < k){
                i++;
            }
            else{
                j--;
            }
        }
        return false;
    }
};


