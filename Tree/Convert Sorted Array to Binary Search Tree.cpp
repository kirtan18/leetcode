https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/611/week-4-july-22nd-july-28th/3827/


class Solution {
    
    TreeNode * solve(vector<int>&nums,int start,int end){      
        if(end <= start)return NULL;       
        int mid = (start+end)/2;
        TreeNode * root = new TreeNode(nums[mid]);
        root->left = solve(nums,start,mid);
        root->right = solve(nums,mid+1,end);
        return root;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums,0,nums.size());
    }
};
