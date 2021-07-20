https://leetcode.com/problems/unique-binary-search-trees-ii/


class Solution {
    vector<TreeNode*> generateBST(int begin, int end){
        
        vector<TreeNode*>v;
        if(begin > end){
            v.push_back(NULL);
            return v;
        }
        
        for(int i = begin ; i <= end ; i++){
            
            vector<TreeNode*>left = generateBST(begin,i-1);
            vector<TreeNode*>right = generateBST(i+1,end);
            
            for(auto l : left){                
                for(auto r : right){                  
                    TreeNode * root = new TreeNode();
                    root->val = i;
                    root->left = l;
                    root->right = r;
                    v.push_back(root);                   
                }
            }
        }
        return v;
    }
    
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*>v;
        if(n == 0)return v;
        
        return generateBST(1,n);
    }
};
