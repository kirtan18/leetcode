// Given the root of a binary tree, return the zigzag level order traversal of its nodes'
// values. (i.e., from left to right, then right to left for the next level and alternate between).


// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[20,9],[15,7]]
// Input: root = [1]
// Output: [[1]]
// Input: root = []
// Output: []


class Solution {
public:
    vector<vector<int>>ret;      
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};
        stack<TreeNode*>s1;
        stack<TreeNode*>s2;
        vector<int>temp;
        s1.push(root);
        int k = 0;
        
        while(!s1.empty() || !s2.empty()){
            
            if(k%2 == 0){
                while(!s1.empty()){
                    TreeNode * curr = s1.top();
                    s1.pop();
                    temp.push_back(curr->val);                    
                    if(curr->left)s2.push(curr->left);
                    if(curr->right)s2.push(curr->right);
                    
                }
                k++;
            }
            else if(k%2 != 0){
                while(!s2.empty()){
                    TreeNode * curr = s2.top();
                    s2.pop();
                    temp.push_back(curr->val);
                    
                    if(curr->right)s1.push(curr->right);
                    if(curr->left)s1.push(curr->left);
                }
                k++;
            }
            ret.push_back(temp);
            temp.clear();   
        }
        return ret;
    }
};
