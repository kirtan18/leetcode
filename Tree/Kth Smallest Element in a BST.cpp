// Given the root of a binary search tree, and an integer k, return the kth (1-indexed) smallest element in the tree.

// Example 1:

// Input: root = [3,1,4,null,2], k = 1
// Output: 1
  
// Example 2:

// Input: root = [5,3,6,2,4,null,null,1], k = 3
// Output: 3

///////////////////////////////////////// 1st Approch //////////////////////////////////////////////
class Solution {
    
    void helper(TreeNode * root , int k , vector<int>&arr){
        
        if(!root)return;
       
        helper(root->left , k , arr);
        arr.push_back(root->val); 
        helper(root->right , k , arr);
    }
    
    
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root)return 0;
        vector<int>arr;
        helper(root, k , arr);
        sort(arr.begin() , arr.end()); 
        cout << arr[k-1];
        return arr[k-1];
        
    }
};

/////////////////////////////////////////    2nd Approch //////////////////////////////////////////////
class Solution {
    
    int solve(TreeNode * root , int&k){
        if(!root)return 0;
        int left = solve(root->left,k);
        if(left)return left;
        k -= 1;
        if(k == 0)return root->val;
        int right = solve(root->right,k);
        return right;
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        return solve(root,k);
    }
};
