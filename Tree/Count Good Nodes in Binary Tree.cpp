// Given a binary tree root, a node X in the tree is named good 
// if in the path from root to X there are no nodes with a value greater than X.
// Return the number of good nodes in the binary tree.


// Input: root = [3,1,4,3,null,1,5]
// Output: 4
// Explanation: Nodes in blue are good.
// Root Node (3) is always a good node.
// Node 4 -> (3,4) is the maximum value in the path starting from the root.
// Node 5 -> (3,4,5) is the maximum value in the path
// Node 3 -> (3,1,3) is the maximum value in the path.



//             In this approch we count max number in  the tree so it is good number in tree 


////////////////////////////////////////////////////////  DFS //////////////////////////////////////////////////////
//////////////////////////////////////////// Time : O(N + H) &&  Space : O(1) ////////////////////////////////////////


class Solution {
   int maxi = 0; 
   void countGood_Nodes(TreeNode * root , int high){
       if(!root)return;
       if(root->val >= high){
           high = root->val;
           maxi++;
       }
       countGood_Nodes(root->left,high);
       countGood_Nodes(root->right,high);
   }
public:
    int goodNodes(TreeNode* root) {
        int high = root->val;
        countGood_Nodes(root,high);
        return maxi;
    }
};
