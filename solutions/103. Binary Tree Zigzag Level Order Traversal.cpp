 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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
