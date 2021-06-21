// Given two binary trees original and cloned and given a reference to a node target in the original tree.

// The cloned tree is a copy of the original tree.

// Return a reference to the same node in the cloned tree.

// Note that you are not allowed to change any of the two trees or the target node and the answer must be a reference to a node in the cloned tree.

// Follow up: Solve the problem if repeated values on the tree are allowed.


// Input: tree = [7,4,3,null,null,6,19], target = 3
// Output: 3
// Explanation: In all examples the original and cloned trees are shown.
//              The target node is a green node from the original tree. 
//              The answer is the yellow node from the cloned tree.




/////////////////////////////////////////////// DFS   Time : O(N) , Space : O(1) //////////////////////////////////////////////////////////

   class Solution {
    TreeNode * ans;
    
    void solve( TreeNode* clon, TreeNode* tar){
        if(!clon)return;
        if(clon->val == tar->val){
            ans = clon;
        }
        solve(clon->left,tar);
        solve(clon->right,tar);
    }
    
    
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        solve(cloned,target);
        return ans;
    }
};
