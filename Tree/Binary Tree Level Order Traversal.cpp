// Given the root of a binary tree, return the level order traversal of its nodes
// ' values. (i.e., from left to right, level by level).



// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]
// Input: root = [1]
// Output: [[1]]
// Input: root = []
// Output: []



class Solution {
public:
    vector<vector<int>>ret;
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(!root)return {};
        queue<TreeNode*>q;
        vector<int>temp;
        q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            
            for(int i = 0 ; i < n ; i++){
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            ret.push_back(temp);
            temp.clear();
        }
        return ret;
    }
};
