// Given a binary tree with the following rules:

// root.val == 0
// If treeNode.val == x and treeNode.left != null, then treeNode.left.val == 2 * x + 1
// If treeNode.val == x and treeNode.right != null, then treeNode.right.val == 2 * x + 2
// Now the binary tree is contaminated, which means all treeNode.val have been changed to -1.

// Implement the FindElements class:

// FindElements(TreeNode* root) Initializes the object with a contaminated binary tree and recovers it.
// bool find(int target) Returns true if the target value exists in the recovered binary tree.


// Input
// ["FindElements","find","find"]
// [[[-1,null,-1]],[1],[2]]
// Output
// [null,false,true]
// Explanation
// FindElements findElements = new FindElements([-1,null,-1]); 
// findElements.find(1); // return False 
// findElements.find(2); // return True 
 


class FindElements {
public:
    set<int>set;
    void dfs(TreeNode * root , int v){
        if(!root)return;
        root->val = v;
        set.insert(v);
        dfs(root->left,2*v+1);
        dfs(root->right,2*v+2);
    }
    
    
    FindElements(TreeNode* root) {
        dfs(root,0);
    }
    
    bool find(int target) {
        if(set.find(target) != set.end()){
            return true;
        }
        return false;
    }
};
